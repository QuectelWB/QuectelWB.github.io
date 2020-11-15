Strtucts
====

Struct 对齐问题
-------

	struct A{
		int a;
		char b;
		short c;
	};

	struct B{
		char b;
		int a;
		short c;
	};

这两个结构体的对象，空间大小不一样，前者8Byte, 12Byte

	a.第一个成员起始于0偏移处；
	b.每个成员按其类型大小和指定对齐参数n中较小的一个进行对齐；
	c.结构体总长度必须为所有对齐参数的整数倍；
	d.对于数组，可以拆开看做n个数组元素。


