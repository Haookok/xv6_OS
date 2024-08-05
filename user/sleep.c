
#include "kernel/types.h"

#include "user/user.h"
// int main(int argc,char* argv[])8 // argc 是命令行总的参数个数
// argv[]是argc 个参数，其中第 。 个参数是程序的全名，以后的参数是命令行后面跟的用户输入的参数
int
main(int argc, char *argv[])
{

//如果命令行参数不等于2个，则打印错误信息
    if(argc != 2)
    {
	//系统调用write(int fd，char *buf，int n)函数输出错误信息

	//参数 fd 是文件描述符，。表示标准输入，1 表示标准输出，2 表示标准错误
	// 参数 buf 是程序中存放写的数据的字符数组
	// 参数n 是要传输的字节数
	//所以这里调用 user/ulib.c 的strlen()函数获取字符串长度字节数
	write(2,"usage: sleep timen",strlen("usage: sleep time\n"));
	//退出程序
	exit(1);
    }
    //把字符串型参数转换为整型
    int time = atoi(argv[1]);
    // 调用系统调用 sleep 函数，传入整型参数
    sleep(time);
    // 正常退出程序
    exit(0);
}
