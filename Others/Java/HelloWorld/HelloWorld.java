public class HelloWorld {
	public static int x=10;
	 // Java程序的入口方法，程序将从这里开始执行
	public static void main(String[] args) {
	int y=1;
	String S;
	System.out.println("Hello World");
//	System.out.println(args.length);
//
	S = String.valueOf(args.length);
	System.out.println("length is   "+ S);


	for (int i=0;i < args.length;i++)
		System.out.println(args[i]);

//	System.out.println(args[]);
	System.out.println(x-y);
	}
}
