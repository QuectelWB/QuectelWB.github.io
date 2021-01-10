Qt
======

QStringList
------

	 QStringList qstrList;
	  qstrList<<"Android" << "Qt Creator" << "Java" << "C++";
	  QStringListIterator strIterator(qstrList);
	  while (strIterator.hasNext())
		qDebug() << strIterator.next() << endl;

	增删改查

	qstrList.insert(0,"C#");
	qstrList.replace(0,"Web");
	bool isflag = qstrList.removeOne("C#");//删除一个指定的元素，删除成功返回true，删除失败返回fasle
	qDebug() << isflag << endl;
	int n = qstrList.removeAll("Java");//删除所有的指定的元素，返回删除的元素个数
	qDebug() << n << endl;
	qstrList.removeAt(2);//删除第三个元素
	qstrList.removeFirst();//删除第一个元素
	qstrList.removeLast();//删除最后一个元素


- QStringList类提供字符串列表。 
- QStringList继承自QList < QString >。与QList一样，QStringList是隐式共享的。它提供了快速的基于索引的访问，以及快速插入和删除。将字符串列表作为值参数传递是快速和安全的。 
- QList的所有功能也适用于QStringList。使用isEmpty（）测试列表是否为空，调用append（）、prepend（）、insert（）、replace（）、removeAll（）、removeAt（）、removeFirst（）和removeOne（）来修改QStringList。 
- 此外，QStringList提供了一些方便的函数，使字符串的处理列表变得更容易


