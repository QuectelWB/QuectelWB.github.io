

Command 模式的命令说明:

	CMD0 GO_IDLE_STATE  Mandatory Mandatory  Used to change from SD to SPI mode /* 使SD卡进入Idle状态 */
	CMD2 ALL_SEND_CID Mandatory  CID not supported by SDIO /* 广播获取卡的CID信息 */
	CMD3 SEND_RELATIVE_ADDR  Mandatory Mandatory  /* 广播获取SD卡所分配的相对地址 */
	CMD4 SET_DSR  Optional    DSR not supported by SDIO 
	CMD5 IO_SEND_OP_COND    Mandatory  
	CMD6 SWITCH_FUNC  Mandatory1 Mandatory1 Added in Part 1 v1.10 
	CMD7 SELECT/DESELECT_CARD Mandatory Mandatory  /* 根据获取指定的RCA,选中SD卡,如果在选中一个卡的状态下,又选中其他的卡,那么之前的卡会自动取消选中,如果发送地址0,则表示取消选中全部卡 */
	CMD9 SEND_CSD  Mandatory    CSD not supported by SDIO /* 获取SD相关的存储信息,如块大小,容量等. */
	CMD10 SEND_CID  Mandatory   CID not supported by SDIO 
	CMD12 STOP_TRANSMISSION  Mandatory /* 停止多块传输操作 */
	CMD13 SEND_STATUS  Mandatory    Card Status includes only SDMEM information /* 获取卡的状态 */
	CMD15 GO_INACTIVE_STATE  Mandatory Mandatory  
	CMD16 SET_BLOCKLEN  Mandatory /* 设置SD卡的块大小,CSD寄存器有描述. */
	CMD17 READ_SINGLE_BLOCK  Mandatory /* 使SD卡进入传输状态,读取单个块 */
	CMD18 READ_MULTIPLE_BLOCK Mandatory /* 使SD卡进入传输状态,读取多个块,直到收到CMD12为止 */
	CMD24 WRITE_BLOCK   Mandatory /* 使SD卡进入传输状态,写入单个块 */   
	CMD25 WRITE_MULTIPLE_BLOCK Mandatory /* 使SD卡进入传输状态,写入多个块 */    
	CMD27 PROGRAM_CSD  Mandatory    CSD not supported by SDIO 
	CMD28 SET_WRITE_PROT  Optional   
	CMD29 CLR_WRITE_PROT  Optional    
	CMD30 SEND_WRITE_PROT  Optional    
	CMD32 ERASE_WR_BLK_START  Mandatory    
	CMD33 ERASE_WR_BLK_END  Mandatory    
	CMD38 ERASE  Mandatory    
	CMD42 LOCK_UNLOCK  Optional    
	CMD52 IO_RW_DIRECT    Mandatory  
	CMD53 IO_RW_EXTENDED    Mandatory  Block mode is optional 
	CMD55 APP_CMD Mandatory /* 特殊指令前命令,在发送ACMD类指令前,需要发送此命令 */  
	CMD56 GEN_CMD  Mandatory    
	ACMD6 SET_BUS_WIDTH  Mandatory /* 设置SD卡的总线位宽,这个需要读取SCR确定 */ 
	ACMD13 SD_STATUS  Mandatory    
	ACMD22 SEND_NUM_WR_BLOCKS  Mandatory    
	ACMD23 SET_WR_BLK_ERASE_COUNT Mandatory     
	ACMD41 SD_APP_OP_COND  Mandatory /* 获取SD电压值 */
	ACMD42 SET_CLR_CARD_DETECT  Mandatory    
	ACMD51 SEND_SCR  Mandatory    SCR not supported by SDIO /* 获取SD卡的SCR寄存器的值 */

2410 SDI控制寄存器:
	
	SDICON 0x5A000000    R/W SDI control register             /* 完成SD卡基础配置,包括大小端,中断允许,时钟使能和重启FIFO */
	SDIPRE 0x5A000004    R/W SDI baud rate prescaler register /* 对SD的时钟分频系数设置 */
	SDICARG 0x5A000008   R/W SDI command argument register    /* 指令的参数存放在这里,不同的命令,参数的位数格式有不用含义 */
	SDICCON 0x5A00000C   R/W SDI command control register     /* 控制指令形式的寄存器,配置SPI还是SDI指令,指令的反馈长度,是否等待反馈,是否运行指令,指令的索引等 */
	SDICSTA 0x5A000010   R/(W) SDI command status register    /* 指令状态寄存器,指令是否超时,传送,结束,CRC是否正确等 */
	SDIRSP0 0x5A000014   R SDI response register 0            /* SD回应状态寄存器,R1的回应都用这个,其他长回应会用到4个. */
	SDIRSP1 0x5A000018   R SDI response register 1
	SDIRSP2 0x5A00001C   R SDI response register 2
	SDIRSP3 0x5A000020   R SDI response register 3
	SDIDTIMER 0x5A000024 R/W SDI data / busy timer register   /* 设置超时时间 */
	SDIBSIZE 0x5A000028  R/W SDI block size register          /* 设置Block的大小,FIFO共填充的数据.单位是字节 */
	SDIDCON 0x5A00002C   R/W SDI data control register        /* 数据控制寄存器,配置是几线传输,数据发送方向,数据传送方式,要传送多少个块的数据等 */
	SDIDCNT 0x5A000030   R SDI data remain counter register   /* 数据保持计数器 */
	SDIDSTA 0x5A000034   R/(W) SDI data status register       /* 数据状态寄存器,数据是否发送完,CRC效验,超时等 */
	SDIFSTA 0x5A000038   R SDI FIFO status register           /* FIFO状态寄存器，DMA传输时不用判断FIFO */
	SDIDAT 0x5A00003C    (Li/W,Li/B, Bi/W) 0x5A00003F(Bi/B) R/W SDI data register /* 数据传输寄存器,要严格读完所请求的数据块,否则遗留的数据位将影响下一次的数据传输 */
	SDIIMSK 0x5A000040   R/W SDI interrupt mask register      /* 中断屏蔽 */

SD/MMC 初始化流程

步骤是：
	1）配置时钟，慢速一般为400K，设置工作模式
	2）发送CMD0，进入空闲态，该指令没有反馈	
	3）发送CMD8，如果有反应，CRC值与发送的值相同，说明该卡兼容SD2.0协议。
	4）发送CMD55+ACMD41，判断SD卡的上电是否正确，短反馈成功说明该卡为SD卡(短反馈第31位置1为HC卡)，否则发送CMD0，有反应说明是MMC卡
	5）发送CMD2，验证SD卡是否接入，长反馈(CID)
	6）发送CMD3，读取SD卡的RCA（地址），短反馈
	7）发送CMD9，读取CSD寄存器获取卡的相关信息
	8）发送CMD7，使能SD卡
	9）配置高速时钟，准备数据传输，一般20M～25M
	10）发送CMD55+ACMD51读取SCR寄存器，SD卡可以通过该值获得位宽，如果是MMC卡则需要使用主线测试来确定卡的位宽。
	11）SD卡发送CMD55+ACMD6配置为4bit数据传输模式(根据SCR读出来的值确定),MMC卡发送CMD6来设置位宽
	12）发送CMD7，使能SD卡，使其进入传输状态)，接着发送CMD16设置块大小(根据前面读取的CSD信息确定)。
	13) 把命令参数设置为0，再次发送CMD7，取消选中所有卡。

SD 读操作(注意:标准卡和HC卡最大区别在于单块或者多块读写时命令的起始地址参数对齐,标准卡是以字节计算为起始地址的,而HC则按块地址作为起始地址.例如,一般情况下从CSD获取的卡信息中,块长度都为512字节大小,那么要访问第一个512字节时,对于标准卡,命令的参数直接写512,而HC卡则写1.另外,标准卡所使用的SD协议有可能是1.0也有可能是2.0,但是HC的卡就一定是2.0的,大部分的SD卡都是2.0的,而最新的XC卡则使用3.0的协议.)
步骤是：
	1）发送CMD7，以卡的相对地址为参数，选中该卡，并使其进入Tran状态
	2）发送CMD17/CMD18，命令的参数需要根据初始化时所判断的卡类型填写，按字节或按块.
	3）循环读取数据
	4）发送CMD12，强制停止所有传输.
	5）发送CMD7，以0作为命令参数,取消所有选中.


SD 卡寄存器

	SCR 该寄存器保存的SD的特殊性信息(例如支持的总线位宽,SD卡的版本),MMC卡没有此寄存器,获取该寄存器的数据需要从数据线读的.
	CSD 该寄存器保存着SD卡的详细信息,如块大小,SD卡的容量大小,文件系统等信息.
	RCA SD的相对地址(SD卡已经保存在芯片内部)
	OCR 该寄存器保存着SD的可供电范围,并且区别是否为HC卡(根据返回的ORC回应第30位是否置1).
	CIA (Card I/O Area)
	CID SD卡的唯一ID号
	CIS (Card Information Structure)跟Linux内核的参数TagList的存放方式很相似,都是以标识号和长度加后续内容表示一个节点.


