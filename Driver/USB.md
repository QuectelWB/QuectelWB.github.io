USB
====

USB Protocol
----

Most of my words quote from 
[USB Introduction](https://beyondlogic.org/usbnutshell/usb1.shtml#Introduction)



**USB Descriptors**

The more common USB descriptors are

	Device Descriptors
	Configuration Descriptors
	Interface Descriptors
	Endpoint Descriptors
	String Descriptors


![](imgs/desctree.gif)



</TABLE>
</CENTER></P>
</UL>
<A NAME="DeviceDescriptors">Device Descriptors</a>
<UL>

<P ALIGN="CENTER"><CENTER><TABLE CELLSPACING=2 CELLPADDING=7 WIDTH=642>
<TR id="head"><TD WIDTH="9%" VALIGN="TOP">
Offset</B></TD>
<TD WIDTH="22%" VALIGN="TOP">
Field</B></TD>
<TD WIDTH="7%" VALIGN="TOP">
Size</B></TD>
<TD WIDTH="12%" VALIGN="TOP">
Value</B></TD>
<TD WIDTH="50%" VALIGN="TOP">
Description</B></TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
0</TD>
<TD WIDTH="22%" VALIGN="TOP">
bLength</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Number</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Size of the Descriptor in Bytes (18 bytes)</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
1</TD>
<TD WIDTH="22%" VALIGN="TOP">
bDescriptorType</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Constant</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Device Descriptor (0x01)</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
2</TD>
<TD WIDTH="22%" VALIGN="TOP">
bcdUSB</TD>
<TD WIDTH="7%" VALIGN="TOP">
2</TD>
<TD WIDTH="12%" VALIGN="TOP">
BCD</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>USB Specification Number which device complies too.</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
4</TD>
<TD WIDTH="22%" VALIGN="TOP">
bDeviceClass</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Class</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Class Code (Assigned by USB Org)</P>
<P>If equal to Zero, each interface specifies its own class code</P>
<P>If equal to 0xFF, the class code is vendor specified.</P>
<P>Otherwise field is valid Class Code.</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
5</TD>
<TD WIDTH="22%" VALIGN="TOP">
bDeviceSubClass</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
SubClass</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Subclass Code (Assigned by USB Org)</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
6</TD>
<TD WIDTH="22%" VALIGN="TOP">
bDeviceProtocol</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Protocol</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Protocol Code (Assigned by USB Org)</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
7</TD>
<TD WIDTH="22%" VALIGN="TOP">
bMaxPacketSize</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Number</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Maximum Packet Size for Zero Endpoint. Valid Sizes are 8, 16, 32, 64</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
8</TD>
<TD WIDTH="22%" VALIGN="TOP">
idVendor</TD>
<TD WIDTH="7%" VALIGN="TOP">
2</TD>
<TD WIDTH="12%" VALIGN="TOP">
ID</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Vendor ID (Assigned by USB Org)</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
10</TD>
<TD WIDTH="22%" VALIGN="TOP">
idProduct</TD>
<TD WIDTH="7%" VALIGN="TOP">
2</TD>
<TD WIDTH="12%" VALIGN="TOP">
ID</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Product ID (Assigned by Manufacturer)</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
12</TD>
<TD WIDTH="22%" VALIGN="TOP">
bcdDevice</TD>
<TD WIDTH="7%" VALIGN="TOP">
2</TD>
<TD WIDTH="12%" VALIGN="TOP">
BCD</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Device Release Number</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
14</TD>
<TD WIDTH="22%" VALIGN="TOP">
iManufacturer</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Index</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Index of Manufacturer String Descriptor</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
15</TD>
<TD WIDTH="22%" VALIGN="TOP">
iProduct</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Index</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Index of Product String Descriptor</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
16</TD>
<TD WIDTH="22%" VALIGN="TOP">
iSerialNumber</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Index</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Index of Serial Number String Descriptor</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
17</TD>
<TD WIDTH="22%" VALIGN="TOP">
bNumConfigurations</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Integer</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Number of Possible Configurations</TD>
</TR>
</TABLE>



</UL>
<A NAME="ConfigurationDescriptors">Device Descriptors</a>
<UL>
<TABLE CELLSPACING=2 CELLPADDING=7 WIDTH=642>
<TR id="head"><TD WIDTH="8%" VALIGN="TOP">
Offset</B></TD>
<TD WIDTH="22%" VALIGN="TOP">
Field</B></TD>
<TD WIDTH="7%" VALIGN="TOP">
Size</B></TD>
<TD WIDTH="12%" VALIGN="TOP">
Value</B></TD>
<TD WIDTH="50%" VALIGN="TOP">
Description</B></TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
0</TD>
<TD WIDTH="22%" VALIGN="TOP">
bLength</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Number</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Size of Descriptor in Bytes</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
1</TD>
<TD WIDTH="22%" VALIGN="TOP">
bDescriptorType</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Constant</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Configuration Descriptor (0x02)</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
2</TD>
<TD WIDTH="22%" VALIGN="TOP">
wTotalLength</TD>
<TD WIDTH="7%" VALIGN="TOP">
2</TD>
<TD WIDTH="12%" VALIGN="TOP">
Number</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Total length in bytes of data returned</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
4</TD>
<TD WIDTH="22%" VALIGN="TOP">
bNumInterfaces</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Number</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Number of Interfaces</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
5</TD>
<TD WIDTH="22%" VALIGN="TOP">
bConfigurationValue</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Number</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Value to use as an argument to select this configuration</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
6</TD>
<TD WIDTH="22%" VALIGN="TOP">
iConfiguration</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Index</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Index of String Descriptor describing this configuration</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
7</TD>
<TD WIDTH="22%" VALIGN="TOP">
bmAttributes</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Bitmap</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>D7 Reserved, set to 1. (USB 1.0 Bus Powered)</P>
<P>D6 Self Powered</P>
<P>D5 Remote Wakeup</P>
<P>D4..0 Reserved, set to 0.</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
8</TD>
<TD WIDTH="22%" VALIGN="TOP">
bMaxPower</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
mA</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Maximum Power Consumption in 2mA units </TD>
</TR>
</TABLE>

Interface Descriptor

<TABLE CELLSPACING=2 CELLPADDING=7 WIDTH=642>
<TR id="head"><TD WIDTH="8%" VALIGN="TOP">
Offset</B></TD>
<TD WIDTH="22%" VALIGN="TOP">
Field</B></TD>
<TD WIDTH="7%" VALIGN="TOP">
Size</B></TD>
<TD WIDTH="12%" VALIGN="TOP">
Value</B></TD>
<TD WIDTH="50%" VALIGN="TOP">
Description</B></TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
0</TD>
<TD WIDTH="22%" VALIGN="TOP">
bLength</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Number</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Size of Descriptor in Bytes (9 Bytes)</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
1</TD>
<TD WIDTH="22%" VALIGN="TOP">
bDescriptorType</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Constant</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Interface Descriptor (0x04)</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
2</TD>
<TD WIDTH="22%" VALIGN="TOP">
bInterfaceNumber</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Number</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Number of Interface</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
3</TD>
<TD WIDTH="22%" VALIGN="TOP">
bAlternateSetting</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Number</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Value used to select alternative setting</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
4</TD>
<TD WIDTH="22%" VALIGN="TOP">
bNumEndpoints</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Number</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Number of Endpoints used for this interface</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
5</TD>
<TD WIDTH="22%" VALIGN="TOP">
bInterfaceClass</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Class</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Class Code (Assigned by USB Org)</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
6</TD>
<TD WIDTH="22%" VALIGN="TOP">
bInterfaceSubClass</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
SubClass</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Subclass Code (Assigned by USB Org)</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
7</TD>
<TD WIDTH="22%" VALIGN="TOP">
bInterfaceProtocol</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Protocol</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Protocol Code (Assigned by USB Org)</TD>
</TR>
<TR id="row"><TD WIDTH="8%" VALIGN="TOP">
8</TD>
<TD WIDTH="22%" VALIGN="TOP">
iInterface</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Index</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Index of String Descriptor Describing this interface</TD>
</TR>
</TABLE>


Endpoint Descriptor

<TABLE CELLSPACING=2 CELLPADDING=7 WIDTH=642>
<TR id="head"><TD WIDTH="9%" VALIGN="TOP">
Offset</B></TD>
<TD WIDTH="22%" VALIGN="TOP">
Field</B></TD>
<TD WIDTH="7%" VALIGN="TOP">
Size</B></TD>
<TD WIDTH="12%" VALIGN="TOP">
Value</B></TD>
<TD WIDTH="50%" VALIGN="TOP">
Description</B></TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
0</TD>
<TD WIDTH="22%" VALIGN="TOP">
bLength</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Number</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Size of Descriptor in Bytes (7 bytes)</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
1</TD>
<TD WIDTH="22%" VALIGN="TOP">
bDescriptorType</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Constant</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Endpoint Descriptor (0x05)</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
2</TD>
<TD WIDTH="22%" VALIGN="TOP">
bEndpointAddress</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Endpoint</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2>Endpoint Address<BR>
Bits 0..3b Endpoint Number.<BR>
Bits 4..6b Reserved. Set to Zero<BR>
Bits 7     Direction 0 = Out, 1 = In (Ignored for Control Endpoints)<BR>
</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
3</TD>
<TD WIDTH="22%" VALIGN="TOP">
bmAttributes</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Bitmap</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2>
Bits 0..1 Transfer Type
<UL>
00 = Control<BR>
01 = Isochronous<BR>
10 = Bulk<BR>
11 = Interrupt<BR>
</UL>
Bits 2..7 are reserved. If Isochronous endpoint, <BR>
Bits 3..2 = Synchronisation Type (Iso Mode)
<UL>
00 = No Synchonisation<BR>
01 = Asynchronous<BR>
10 = Adaptive<BR>
11 = Synchronous<BR>
</UL>
Bits 5..4 = Usage Type (Iso Mode)
<UL>
00 = Data Endpoint<BR>
01 = Feedback Endpoint<BR>
10 = Explicit Feedback Data Endpoint<BR>
11 = Reserved<BR>
</UL>
</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
4</TD>
<TD WIDTH="22%" VALIGN="TOP">
wMaxPacketSize</TD>
<TD WIDTH="7%" VALIGN="TOP">
2</TD>
<TD WIDTH="12%" VALIGN="TOP">
Number</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Maximum Packet Size this endpoint is capable of sending or receiving</TD>
</TR>
<TR id="row"><TD WIDTH="9%" VALIGN="TOP">
6</TD>
<TD WIDTH="22%" VALIGN="TOP">
bInterval</TD>
<TD WIDTH="7%" VALIGN="TOP">
1</TD>
<TD WIDTH="12%" VALIGN="TOP">
Number</TD>
<TD WIDTH="50%" VALIGN="TOP">
<FONT FACE="Arial" SIZE=2><P>Interval for polling endpoint data transfers. Value in frame counts. Ignored for Bulk &amp; Control Endpoints. Isochronous must equal 1 and field may range from 1 to 255 for interrupt endpoints.</TD>
</TR>
</TABLE>


<P ALIGN="CENTER"><CENTER><TABLE CELLSPACING=2 CELLPADDING=7 WIDTH=536>
<TR id="head"><TD WIDTH="10%" VALIGN="MIDDLE" HEIGHT=24>
Offset</B></TD>
<TD WIDTH="22%" VALIGN="MIDDLE" HEIGHT=24>
Field</B></TD>
<TD WIDTH="8%" VALIGN="MIDDLE" HEIGHT=24>
Size</B></TD>
<TD WIDTH="14%" VALIGN="MIDDLE" HEIGHT=24>
Value</B></TD>
<TD WIDTH="46%" VALIGN="MIDDLE" HEIGHT=24>
Description</B></TD>
</TR>
<TR id="row"><TD VALIGN="TOP">
0</TD>
<TD VALIGN="TOP">
bmRequestType</TD>
<TD VALIGN="TOP">
1</TD>
<TD VALIGN="TOP">
Bit-Map</TD>
<TD VALIGN="TOP">
<FONT FACE="Arial" SIZE=2>
<B>D7 Data Phase Transfer Direction</B><BR>
&#9;0 = Host to Device<BR>
&#9;1 = Device to Host<BR>
<B>D6..5 Type</B><BR>
&#9;0 = Standard<BR>
&#9;1 = Class<BR>
&#9;2 = Vendor<BR>
&#9;3 = Reserved<BR>
<B>D4..0 Recipient</B><BR>
&#9;0 = Device<BR>
&#9;1 = Interface<BR>
&#9;2 = Endpoint<BR>
&#9;3 = Other<BR>
4..31 = Reserved<BR>
</TD>
</TR>
<TR id="row"><TD VALIGN="MIDDLE">
1</TD>
<TD VALIGN="MIDDLE">
bRequest</TD>
<TD VALIGN="MIDDLE">
1</TD>
<TD VALIGN="MIDDLE">
Value</TD>
<TD VALIGN="MIDDLE">
<FONT FACE="Arial" SIZE=2><P>Request</TD>
</TR>
<TR id="row"><TD VALIGN="MIDDLE" HEIGHT=30>
2</TD>
<TD VALIGN="MIDDLE" HEIGHT=30>
wValue</TD>
<TD VALIGN="MIDDLE" HEIGHT=30>
2</TD>
<TD VALIGN="MIDDLE" HEIGHT=30>
Value</TD>
<TD VALIGN="MIDDLE" HEIGHT=30>
<FONT FACE="Arial" SIZE=2><P>Value</TD>
</TR>
<TR id="row"><TD VALIGN="MIDDLE" HEIGHT=30>
4</TD>
<TD VALIGN="MIDDLE" HEIGHT=30>
wIndex</TD>
<TD VALIGN="MIDDLE" HEIGHT=30>
2</TD>
<TD VALIGN="MIDDLE" HEIGHT=30>
Index or Offset</TD>
<TD VALIGN="MIDDLE" HEIGHT=30>
<FONT FACE="Arial" SIZE=2><P>Index</TD>
</TR>
<TR id="row"><TD VALIGN="MIDDLE" HEIGHT=30>
6</TD>
<TD VALIGN="MIDDLE" HEIGHT=30>
wLength</TD>
<TD VALIGN="MIDDLE" HEIGHT=30>
2</TD>
<TD VALIGN="MIDDLE" HEIGHT=30>
Count</TD>
<TD VALIGN="MIDDLE" HEIGHT=30>
<FONT FACE="Arial" SIZE=2><P>Number of bytes to transfer if there is a data phase</TD>
</TR>
</TABLE>
</CENTER></P>

**Standard Device Requests**

<TABLE CELLSPACING=2 CELLPADDING=7 WIDTH=642>
<TR id="head"><TD WIDTH="17%" VALIGN="TOP">
bmRequestType</B></TD>
<TD WIDTH="24%" VALIGN="TOP">
bRequest</B></TD>
<TD WIDTH="15%" VALIGN="TOP">
wValue</B></TD>
<TD WIDTH="15%" VALIGN="TOP">
wIndex</B></TD>
<TD WIDTH="15%" VALIGN="TOP">
wLength</B></TD>
<TD WIDTH="15%" VALIGN="TOP">
Data</B></TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
1000 0000b </TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
GET_STATUS (0x00)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero </TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Two</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Device Status</TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
0000 0000b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
CLEAR_FEATURE (0x01)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Feature Selector</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
None</TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
0000 0000b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
SET_FEATURE (0x03)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Feature Selector</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
None</TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
<A NAME="GetDescriptor"></A>
0000 0000b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
SET_ADDRESS (0x05)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Device Address</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
None</TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
1000 0000b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
GET_DESCRIPTOR (0x06)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Descriptor Type &amp; Index</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero or Language ID</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Descriptor Length</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Descriptor</TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
0000 0000b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
SET_DESCRIPTOR (0x07)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Descriptor Type &amp; Index</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero or Language ID</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Descriptor Length</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Descriptor</TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
1000 0000b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
GET_CONFIGURATION (0x08)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
1</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Configuration Value</TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
0000 0000b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
SET_CONFIGURATION (0x09)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Configuration Value</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
None</TD>
</TR>
</TABLE>


**Standard Interface Requests**

<TABLE CELLSPACING=2 CELLPADDING=7 WIDTH=642>
<TR id="head"><TD WIDTH="17%" VALIGN="TOP">
bmRequestType</B></TD>
<TD WIDTH="24%" VALIGN="TOP">
bRequest</B></TD>
<TD WIDTH="15%" VALIGN="TOP">
wValue</B></TD>
<TD WIDTH="15%" VALIGN="TOP">
wIndex</B></TD>
<TD WIDTH="15%" VALIGN="TOP">
wLength</B></TD>
<TD WIDTH="15%" VALIGN="TOP">
Data</B></TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
1000 0001b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
GET_STATUS (0x00)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Interface</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Two</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Interface Status</TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
0000 0001b </TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
CLEAR_FEATURE (0x01)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Feature Selector</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Interface</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
None</TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
0000 0001b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
SET_FEATURE (0x03)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Feature Selector</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Interface</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
None</TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
1000 0001b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
GET_INTERFACE (0x0A)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Interface</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
One</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Alternate Interface</TD>
<A NAME="SetInterface"></A>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
0000 0001b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
SET_INTERFACE (0x11)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Alternative Setting</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Interface</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
None</TD>
</TR>
</TABLE>


**Standard Endpoint Requests**

<TABLE CELLSPACING=2 CELLPADDING=7 WIDTH=642>
<TR id="head"><TD WIDTH="17%" VALIGN="TOP">
bmRequestType</B></TD>
<TD WIDTH="24%" VALIGN="TOP">
bRequest</B></TD>
<TD WIDTH="15%" VALIGN="TOP">
wValue</B></TD>
<TD WIDTH="15%" VALIGN="TOP">
Windex</B></TD>
<TD WIDTH="15%" VALIGN="TOP">
wLength</B></TD>
<TD WIDTH="15%" VALIGN="TOP">
Data</B></TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
1000 0010b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
GET_STATUS (0x00)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Endpoint</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Two</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Endpoint Status</TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
0000 0010b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
CLEAR_FEATURE (0x01)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Feature Selector</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Endpoint</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
None</TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
0000 0010b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
SET_FEATURE (0x03)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Feature Selector</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Endpoint</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
None</TD>
</TR>
<TR id="row"><TD WIDTH="17%" VALIGN="MIDDLE">
1000 0010b</TD>
<TD WIDTH="24%" VALIGN="MIDDLE">
SYNCH_FRAME (0x12)</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Zero</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Endpoint</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
Two</TD>
<TD WIDTH="15%" VALIGN="MIDDLE">
FrameNumber</TD>
</TR>
</TABLE>


从Linux源码分析
----



USB for Linux
-------
[USB Patch](https://www.spinics.net/lists/linux-usb/)


GobiNet Driver 分析
-----

	
	GobiUSBNetProbe
			...
			usb_control_msg(
				interface_to_usbdev(pIntf),
				usb_sndctrlpipe(interface_to_usbdev(pIntf), 0),
				0x22, //USB_CDC_REQ_SET_CONTROL_LINE_STATE
				0x21, //USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE
				1, //active CDC DTR
				pIntf->cur_altsetting->desc.bInterfaceNumber,
				NULL, 0, 100);

pIntf->cur_altsetting->desc.bInterfaceNumber ---> 4

usbmon log:

	ffff8ff2d74da840 2154856978 C Co:2:005:0 0 13 >
	ffff8ff49068b780 2154857014 S Co:2:005:0 s 21 22 0001 0004 0000 0
	ffff8ff49068b780 2154857102 C Co:2:005:0 0 0

USB PM
-----

从3.10开始，CONFIG_USB_SUSPEND --> eliminated

早期内核，USB的dynamic suspend 需要打开 CONFIG_USB_SUSPEND ，并且依赖于 CONFIG_PM_RUNTIME.




参考资源
------

[http://www.linux-usb.org/](http://www.linux-usb.org/)

[]()



:)
