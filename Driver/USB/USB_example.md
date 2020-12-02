USB 驱动例子
------

from [Writing a Linux Kernel Driver for an Unknown USB Device](http://matthias.vallentin.net/blog/2007/04/writing-a-linux-kernel-driver-for-an-unknown-usb-device/)




	#define ML_STOP         0x00
	#define ML_UP           0x01
	#define ML_DOWN         0x02
	#define ML_LEFT         0x04
	#define ML_RIGHT        0x08
	#define ML_UP_LEFT      (ML_UP | ML_LEFT)
	#define ML_DOWN_LEFT    (ML_DOWN | ML_LEFT)
	#define ML_UP_RIGHT     (ML_UP | ML_RIGHT)
	#define ML_DOWN_RIGHT   (ML_DOWN | ML_RIGHT)
	#define ML_FIRE         0x10

	#define ML_MAX_UP       0x80        /* 80 00 00 00 00 00 00 00 */
	#define ML_MAX_DOWN     0x40        /* 40 00 00 00 00 00 00 00 */
	#define ML_MAX_LEFT     0x04        /* 00 04 00 00 00 00 00 00 */
	#define ML_MAX_RIGHT    0x08        /* 00 08 00 00 00 00 00 00 */


	struct usb_ml {
	    /* One structure for each connected device */
	};

	static struct usb_device_id ml_table [] = {
	    { USB_DEVICE(ML_VENDOR_ID, ML_PRODUCT_ID) },
	    { }
	};

	static int ml_open(struct inode *inode, struct file *file)
	{
	    /* open syscall */
	}
	static int ml_release(struct inode *inode, struct file *file)
	{
	    /* close syscall */
	}

	static ssize_t ml_write(struct file *file, const char __user *user_buf, size_t
		count, loff_t *ppos);
	{
	    /* write syscall */
	}

	static struct file_operations ml_fops = {
	    .owner =    THIS_MODULE,
	    .write =    ml_write,
	    .open =     ml_open,
	    .release =  ml_release,
	};

	static int ml_probe(struct usb_interface *interface, const struct usb_device_id
		*id)
	{
	    /* called when a USB device is connected to the computer. */
	}

	static void ml_disconnect(struct usb_interface *interface)
	{
	    /* called when unplugging a USB device. */
	}

	static struct usb_driver ml_driver = {
	    .name = "missile_launcher",
	    .id_table = ml_table,
	    .probe = ml_probe,
	    .disconnect = ml_disconnect,
	};

	static int __init usb_ml_init(void)
	{
	    /* called on module loading */
	}

	static void __exit usb_ml_exit(void)
	{
	    /* called on module unloading */
	}

	module_init(usb_ml_init);
	module_exit(usb_ml_exit);



	static int ml_probe(struct usb_interface *interface,
			    const struct usb_device_id *id)
	{
	    struct usb_device *udev = interface_to_usbdev(interface);
	    struct usb_ml *dev = NULL;
	    struct usb_host_interface *iface_desc;
	    struct usb_endpoint_descriptor *endpoint;
	    int i, int_end_size;
	    int retval = -ENODEV;

	    if (! udev)
	    {
		DBG_ERR("udev is NULL");
		goto exit;
	    }

	    dev = kzalloc(sizeof(struct usb_ml), GFP_KERNEL);
	    if (! dev)
	    {
		DBG_ERR("cannot allocate memory for struct usb_ml");
		retval = -ENOMEM;
		goto exit;
	    }

	    dev->command = ML_STOP;

	    init_MUTEX(&dev->sem);
	    spin_lock_init(&dev->cmd_spinlock);

	    dev->udev = udev;
	    dev->interface = interface;
	    iface_desc = interface->cur_altsetting;

	    /* Set up interrupt endpoint information. */
	    for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i)
	    {
		endpoint = &iface_desc->endpoint[i].desc;

		if (((endpoint->bEndpointAddress & USB_ENDPOINT_DIR_MASK) == USB_DIR_IN)
			&& ((endpoint->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK) ==
			    USB_ENDPOINT_XFER_INT))
		    dev->int_in_endpoint = endpoint;

	    }
	    if (! dev->int_in_endpoint)
	    {
		DBG_ERR("could not find interrupt in endpoint");
		goto error;
	    }

	    /* ... */

	    /* We can register the device now, as it is ready. */
	    retval = usb_register_dev(interface, &ml_class);

	    /* ... */
	}



	memset(&buf, 0, sizeof(buf));
	buf[0] = cmd;

	/* The interrupt-in-endpoint handler also modifies dev->command. */
	spin_lock(&dev->cmd_spinlock);
	dev->command = cmd;
	spin_unlock(&dev->cmd_spinlock);

	retval = usb_control_msg(dev->udev,
		usb_sndctrlpipe(dev->udev, 0),
		ML_CTRL_REQUEST,
		ML_CTRL_REQEUST_TYPE,
		ML_CTRL_VALUE,
		ML_CTRL_INDEX,
		&buf,
		sizeof(buf),
		HZ * 5);

	if (retval < 0)
	{
	    DBG_ERR("usb_control_msg failed (%d)", retval);
	    goto unlock_exit;
	}



	static void ml_ctrl_callback(struct urb *urb, struct pt_regs *regs)
	{
	    struct usb_ml *dev = urb->context;
	    dev->correction_required = 0;
	}


	static void ml_int_in_callback(struct urb *urb, struct pt_regs *regs)
	{
		/* ... */

		if (dev->int_in_buffer[0] & ML_MAX_UP && dev->command & ML_UP)
		{
		    dev->command &= ~ML_UP;
		    dev->correction_required = 1;
		} else if (dev->int_in_buffer[0] & ML_MAX_DOWN &&
			dev->command & ML_DOWN)
		{
		    dev->command &= ~ML_DOWN;
		    dev->correction_required = 1;
		}

		if (dev->int_in_buffer[1] & ML_MAX_LEFT && dev->command & ML_LEFT)
		{
		    dev->command &= ~ML_LEFT;
		    dev->correction_required = 1;
		} else if (dev->int_in_buffer[1] & ML_MAX_RIGHT &&
			dev->command & ML_RIGHT)
		{
		    dev->command &= ~ML_RIGHT;
		    dev->correction_required = 1;
		}

		/* ... */
	}




