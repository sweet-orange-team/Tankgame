/*

http://www.vbgood.com/api.html
http://hi.baidu.com/3582077/item/9cc3483b581f53c5392ffae3

第一个：FindWindow根据窗口类名或窗口标题名来获得窗口的句柄，该函数返回窗口的句柄，
这个函数的定义是这样的 HWND WINAPI FindWindow(LPCSTR lpClassName, LPCSTR lpWindowName); 第一个参数填窗口的类名，第二个填窗口的标题名，其实是不需要同时填两个参数的，也就是说，你只要知道窗口的类名或窗口的标题就可以了，没有的那个就用NULL代替。比如现在有一个窗口名为"无标题.txt - 记事本"的记事本程序。那么我就可以用上面的函数获得这个窗口的句柄，那获得了这个窗口的句柄我可以干什么呢？作用可大了，因为很多操作窗口的函数，都需要窗口句柄作参数，如移动、改变窗口大小的MoveWindow函数，在这里举个例子，大家就更能体会到这个FindWindow的用法、用处。

FindWindow例子：已知一个窗口名称，写一个程序关闭该窗口，假设当前电脑正有一个窗口名为"无标题.txt - 记事本"的记事本程序运行

#include<windows.h>//API函数的头文件
int main()
{
	HWND wnd;//定义一个窗口句柄变量，用以存储找到的窗口句柄
	wnd = FindWindow(NULL, "无标题.txt - 记事本");//获得窗口名为"无标题.txt - 记事本"的窗口句柄
	SendMessage(wnd, WM_CLOSE, 0, 0);//调用SendMessage函数，发送一个WM_CLOSE（关闭）消息给wnd窗口句柄。
	return 0;
}

如果要根据窗口类名来获得窗口句柄话，只要给函数的第一个参数填类名，第二个参数窗口名填NULL，即可，用Spy++可查看窗口类名。

第二个：SendMessage根据窗口句柄发送一个消息给窗口
函数定义：LRESULT SendMessage（HWND hWnd，UINT Msg，WPARAM wParam，LPARAM IParam）；
第一个参数是窗口句柄，第二参数个是消息类型，下面的消息表列举了所有消息，第三，四个参数是消息附带信息，解释依赖于消息类型，比如一个字符消息（WM_CHAR), 那么第三个参数就储存有一个字符的ASCII码。
消息机制大家都应该知道吧，Windows是基于消息的系统，鼠标移动键盘按键都会产生消息。
接下来举一个例子，发送一个WM_CHAR消息给窗口，也就是模仿键盘按键，接收消息的窗口依旧以"无标题.txt - 记事本"为例：

SendMessage例子：模仿键盘按键

#include<windows.h>
int main()
{
	HWND wnd;
	wnd = FindWindow(NULL, "无标题.txt - 记事本");
	while (1)
	{
		SendMessage(wnd, WM_CHAR, WPARAM('a'), 0);
		Sleep(300);
	}
	return 0;
}
呵呵上面的例子是不是没用，这是为什么呢，哪里出错了吗？错倒是没有错，只是窗口句柄有问题，消息发送给了主窗口。接收消息的窗口不对。记事本窗口界面有些有什么东西呢？菜单，编辑框，状态栏等控件，控件也是窗口，既然是窗口，那当然它们也有窗口句柄，而在记事本里是在哪里打字的？编辑框控件里打字的嘛！所以消息应该发送编辑框控件，那如何获得记事本里编辑框控件的窗口句柄呢？用FindWindow吗？不知道编辑框窗口标题名，类名也不知道，当然也有其它方法获取编辑框窗口标题名和窗口类名，如Spy++。关于如何获得编辑框句柄，将在以后的函数中会有介绍，这里我们就用WindowFromPoint这个函数来获取，这个函数获取窗口句柄的方法比较笨，（相对于我这个例子来说），这个函数是根据什么来获取窗口句柄的呢？根据屏幕坐标点，如屏幕坐标点20，20，当前是哪个窗口占有，就返回哪个窗口的句柄。有了这个函数，我们还需要一个函数GetCursorPos获取鼠标当前位置（针对于屏幕）；
可行的例子：模仿键盘按键：
#include<windows.h>
int main()
{
	POINT curpos;//一个可储存坐标点的结构体变量，x横坐标，y,纵坐标，如curpos.x curpos.y
	while (1)
	{
		GetCursorPos(&curpos);//获取当前鼠标的位置，位置将储存在curpos里。
		HWND hWnd = WindowFromPoint(curpos);//根据curpos所指的坐标点获取窗口句柄
		SendMessage(hWnd, WM_CHAR, WPARAM('g'), 0);//发送一个字符（按键）消息g给当前鼠标所指向的窗口句柄
		Sleep(300);//睡眠三百毫秒，相当于等待三分之一秒
	}
}
这个程序一运行后，只要把鼠标指向要输入字符的窗口句柄，那么就相当于键盘每三分之一秒按了一个g键，试试吧！
如果这样觉得模仿键盘按键太麻烦的话，那么就用keybd_event这个函数，这个专门用于模仿键盘按键的，关于怎么用，自己百度一搜，就知道了。既然SendMessage能模仿键盘按键的话，那也能模仿鼠标左击，右击。而此时SendMessage函数第三，四个参数的解释就是储存有鼠标左击，右击时的位置。如模仿鼠标右击，想一想，一次鼠标右击有哪几步，分别是鼠标右键按下，鼠标右键松开，如果你按下鼠标右键不松开，那它是不是鼠标右击，不是的，直到你松开鼠标右键，才能算是一次完整的鼠标右击.鼠标右键按下的消息类型是“WM_RBUTTONDOWN”，右键松开的消息是“WM_RBUTTONUP”，那么一次完整的鼠标右击应该是：
SendMessage(wnd, WM_RBUTTONDOWN, 0, 0);//鼠标右键按下,第三，四个参数说明了鼠标按下时的位置
Sleep(100);//间隔100毫秒
SendMessage(wnd, WM_RBUTTONUP, 0, 0);//鼠标右键松开
同样，也有一个专门模仿鼠标动作的函数，mouse_event这个函数，可以模仿鼠标的移动，单击，双击等。以后会有专门介绍。

第三个：GetCursorPos获取鼠标当前位置（屏幕）

这个函数在SendMessage函数有介绍，这里仅举一个例子，在界面里不停的输出鼠标当前位置。
#include<windows.h>
#include<stdio.h>
int main()
{
	POINT curpos;
	while (1)
	{
		GetCursorPos(&curpos);
		printf("x:%d,y:%d", curpos.x, curpos.y);
		Sleep(300);
		printf("\n");
	}
}


第四个：WindowFromPoint根据坐标点获得对应的窗口句柄
在SendMessage有解释，这里仅举一个例子，鼠标指向哪个窗口，就关闭哪个窗口。
#include<windows.h>
int mai()
{
	Sleep(2500);//等待一会儿，用于把鼠标移到其它窗口上去，避免指向本身进程的窗口，关掉自己的窗口。
	POINT curpos;
	while (1)
	{
		GetCursorPos(&curpos);
		HWND wnd = WindowFromPoint(curpos);
		SendMessage(wnd, WM_CLOSE, 0, 0);
		Sleep(300);

	}

}

第五个MoveWindow根据窗口句柄移动窗口，改变窗口大小
函数定义：BOOL MoveWindow(HWND hWnd, int X, int Y, intnWidth, int nHeight, BOOL bRepaint);
hWnd是要改变大小的窗口的句柄，x, y相对于屏幕的坐标，窗口左上角的位置与之相对应，nWidth和nHeight是窗口新的宽高，bRepaint指定窗口是否重画。
这里依旧以"无标题.txt - 记事本"为例子，改变这个窗口大小，并把窗口移到左上角去。
#include<windows.h>
int main()
{
	HWND wnd;
	wnd = FindWindow(NULL, "无标题.txt - 记事本");
	MoveWindow(wnd, 0, 0, 220, 120, NULL);
	return 0;
}
第六个ShowWindow设置窗口显示状态，如隐藏，最大化，最小化

函数定义BOOL ShowWinow(HWND hWnd, int nCmdShow);
SW_HIDE：隐藏窗口并激活其他窗口。第一个参数hWnd指明了窗口句柄，第二个参数指明了窗口的状态，现在给出第二个参数常用取值范围：
SW_MAXIMIZE：最大化指定的窗口。
SW_MINIMIZE：最小化指定的窗口并且激活在Z序中的下一个顶层窗口。
SW_RESTORE：激活并显示窗口。如果窗口最小化或最大化，则系统将窗口恢复到原来的尺寸和位置。在恢复最小化窗口时，应用程序应该指定这个标志。
SW_SHOW：在窗口原来的位置以原来的尺寸激活和显示窗口。
ShowWindow例子：程序运行后，在桌面上隐藏一个指定的窗口，并在4秒后再将其显示
#include<windows.h>
int main()
{
	HWND wnd;
	wnd = FindWindow(NULL, "无标题.txt - 记事本");
	ShowWindow(wnd, SW_HIDE);
	Sleep(5000);
	ShowWindow(wnd, SW_SHOW);
	return 0;
}


第七个SetCursorPos设置鼠标的位置、把鼠标移动到指定的位置
函数定义：BOOL SetCursorPos(int x, int y);
这个函数的两个参数我想大家应该知道是什么意思吧，屏幕的坐标点。
直接看例子：
#include<windows.h>
int main()
{
	int sec = 0;
	while (sec < 200)
	{
		SetCursorPos(rand() % 1024, rand() % 768);//随机设置鼠标的位置
		Sleep(20);
		sec++;
	}
	return 0;
}

第八个CopyFile复制一个文件

如何复制一个文件，比如，我要把E盘的abb.txt的文本文件复制到d盘的zhengyong.txt, 则调用语句
CopyFile("e:\\abb.txt", "d:\\zhengyong.txt", FALSE); 即可。
第三个参数有以下说明：
如果设为TRUE（非零），那么一旦目标文件已经存在，则函数调用会失败。否则目标文件会被覆盖掉。

第九个DeleteFile删除一个文件
如何删除一个文件，语句：DeleteFile("e\\abb.txt"); 既是删除
如果目标为隐藏或只读，则无用。
第十个CreateDirectory创建一个文件夹（目录）
假如E盘下什么文件也没有
CreateDirectory("e:\\aaa\\bbb", NULL); 这样是错的，不能同时建两个文件，除非E盘下已经有了个aaa文件夹了。
这样是对的CreateDirectory("e:\\aaa", NULL);
http://hi.baidu.com/3582077/item/f032b82bbbfb71c0ee10f1e3

第十一个：GetClientRect获得窗口大小(客户区）

	看例子：
#include<windows.h>
#include<stdio.h>
	int main(int argc, char* argv[])
{
	HWND wnd;
	while (1)
	{
		wnd = FindWindow(NULL, "无标题.txt - 记事本");
		RECT rect;//专门用来存储窗口大小
		GetClientRect(wnd, &rect);//获取窗口大小
		printf("%d,%d,%d,%d\n", rect.left, rect.top, rect.right, rect.bottom);//输出窗口大小，试着用鼠标改变窗口大小
		Sleep(300);
	}
}

第十二个：GetWindowRect获得窗口大小（相对屏幕）
例子：
#include<windows.h>
#include<stdio.h>
int main(int argc, char* argv[])
{
	HWND wnd;
	while (1)
	{
		wnd = FindWindow(NULL, "无标题.txt - 记事本");
		RECT rect;//专门用来存储窗口大小
		GetWindowRect(wnd, &rect);//获取窗口大小
		printf("%d,%d,%d,%d\n", rect.left, rect.top, rect.right, rect.bottom);//输出窗口大小，试着用鼠标改变窗口大小
		Sleep(300);
	}
}

第十三个FindFirstFile寻找文件以及获得文件的信息


这里举一个例子吧，列举E盘第一目录下的所有文件，包括文件夹，结合FindNextFile


#include<windows.h>
#include<stdio.h>
int main()
{
	BOOL done = TRUE;
	WIN32_FIND_DATA fd;
	HANDLE hFind = FindFirstFile("e:\\*.*", &fd);//第一个参数是路径名，可以使用通配符，懂DOS的人应该知道吧！fd存储有文件的信息
	while (done)
	{
		printf("%s\n", fd.cFileName);
		done = FindNextFile(hFind, &fd); //返回的值如果为0则没有文件要寻了
	}
	return 0;
}
当然也可以直接找一个文件，不使用通配符，但这样有什么意义呢？，如FindFirstFile("e:\\aaa.txt", &fd); 其实这个可以获取一个文件的信息，如文件是不是隐藏的，或者有没有只读属性等。
当然通过控制通配符，也可以寻找特定类型的文件，比如我只要找文本文件，那么就是这个语句FindFirstFile("e:\\*.txt", &fd); 就行了，关键看你自己灵活运用。
前面说过fd里存储有文件的信息，那怎么根据fd里面的成员判断这个文件的属性，文件是否隐藏，是不是文件夹。
fd里的dwFileAttributes存储有文件的信息，如判断是否为文件夹，只要把这个变量和FILE_ATTRIBUTE_DIRECTORY进行按位与运算，如果不为0的话，表明为文夹件，如if(fd.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) printf("%s是文件夹\n", fd.cFileName);
其它判断也是一样，现在给出文件的属性(常用几个）：FILE_ATTRIBUTE_HIDDEN（隐藏）
	FILE_ATTRIBUTE_READONLY（只读）FILE_ATTRIBUTE_SYSTEM（系统）

	第十四个FindNextFile寻找文件
	参照FindFirstFile函数的例子!
	第十五个MoveFile移动文件
	如把一个盘里的文本移到另一个盘里去 : MoveFile("e:\\a.txt", "d:\\abc.txt"); 即可，意思把e盘下的a.txt移到d盘下去，并改名为abc.txt
	第六个GetClassName根据窗口句柄获得窗口类名
	函数定义：int GetClassName(HWND hWnd, LPTSTR IpClassName, intnMaxCount)；
	这种函数不需要再解释了吧，前面有太多类似的例子。

	第十七个SetFileAttributes设置文件属性
	函数定义：BOOL SetFileAttributes(LPCTSTRlpFileName, DWORDdwFileAttributes);
这个函数的第二个参数dwFileAttributes和前面讲过的WIN32_FIND_DATA结构里的dwFileAttributes成员相对应。假设E盘第一目录下有一个文本文件a.txt的正常文件，我要把它设为只读和隐藏那要如何做呢？在前面介绍过WIN32_FIND_DATA结构里dwFileAttributes成员的几个常用属性，根据这个我们知道隐藏是FILE_ATTRIBUTE_HIDDEN，只读是FILE_ATTRIBUTE_READONLY。
那么把E盘下文本文件的属性设为隐藏和只读的语句就是：
SetFileAttributes("e:\\a.txt", FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY);
(明：这个函数同样也能设置文件夹属性）
	虽然这个语句可以达到要求，但不建议用，因为会覆盖掉文件的原来属性，也就是说如果这个文件之前有系统属性（系统文件）的话，那么这个语句一旦执行后，文件就只有隐藏和只读属性了。
	比如一个文件原先就有隐藏属性，依旧以a.txt为例子，那么我把它设为只读，是不是这个语句就可以呢？


	SetFileAttributes("e:\\a.txt", FILE_ATTRIBUTE_READONLY）; 这样的话，虽然文件有只读属性了，但隐藏属性却没有了。


		那要如何在不覆盖掉原来的属性下，把文件设为只读呢，其实说了这么多的废话，总结起来就一句话：如何增加一个文件的属性！


		前提是要获得这个文件的原有属性：获得文件的属性，在FindFirstFile函数讲过。好吧！直接看例子：


		假设e盘的a.txt文件属性为隐藏，给它增加只读属性：
#include<windows.h>
		int main()


{
	WIN32_FIND_DATA fd;
	FindFirstFile("e:\\a.txt", &fd);
	fd.dwFileAttributes |= FILE_ATTRIBUTE_READONLY;//在原来的属性下增加只读属性
	SetFileAttributes("e:\\a.txt", fd.dwFileAttributes);//设置文件的属性
	return 0;
}
第二个例子：如何去掉一个文件的属性


（补习一下，懂的人直接跳过）


我想懂这里的按位或、按位与或者按位异或运算的人应该知道该如何去掉一个文件的属性。其实一个文件信息都是以二进制码说明的。


比如一个八位二进制码：10000010，这里的每一位是不是只有0和1取值，不是0，就是1，正好可以表示一个文件属性的有无，如这个文件是隐藏的吗？只有是和不是，这样我们规定把这八位二进制码的第一位用于确定文件是否具有隐藏属性，如果为1那便是隐藏，无则没有，以此类推第二位就代表文件的只读，第三位系统。。。但要如何判断呢，或者把某一位的值改变呢，用按位运算就可以，00000010，我要把第2位的值设为0，其它位上的值保持不变，用按位异或运算即可，与00000010进行按位异或运算，但这里并不是与它本身进行运算，不管任何八位二进制数的值是多少只要与00000010进行按位异或运算，那第二位都会变成0，而其它的位保持不变。这样为了方便，我们就把00000010进行宏定义，方便记忆，这个二进制数的十进制为2。宏定义#define FILE_ATTRIBUTE_READONLY 2


明白了这个我们就来清除一个文件的一种属性吧！


清除一个文件的隐藏属性，假设a.txt为隐藏文件：


#include<windows.h>
int main()


{
	WIN32_FIND_DATA fd;
	FindFirstFile("e:\\a.txt", &fd);//获取文件信息
	fd.dwFileAttributes ^= FILE_ATTRIBUTE_HIDDEN;//在原来的属性下删除隐藏属性
	SetFileAttributes("e:\\a.txt", fd.dwFileAttributes);//设置文件的属性
	return 0;
}


如果单单只针对文件的属性进行操作的话，可以用GetFileAttributes函数获取文件的属性，该函数只一个参数，那就是文件的路径，函数返回一个DWORD值，包含文件属性信息。


第十八个ShellExecute运行一个程序
函数定义 : ShellExecute(HWND hwnd, LPCSTR lpOperation, LPCSTRlpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd);
第一个参数hwnd是父窗口的句柄, 可以为NULL, 第二个参数lpOperation表示行为, 第三个参数lpFile是程序的路径名, 第四个参数lpParameters是给所打开程序的参数, 可以为NULL, 第五个参数lpDirectory可以为NULL, 第六个参数nShowCmd跟ShowWindow函数的第二个参数一样, 作用也一样, 如果打开的程序有窗口的话, 这个参数就指明了窗口如何显示.
例如打开一个记事本:
ShellExecute(NULL, "open", "NOTEPAD.EXE", NULL, NULL, SW_SHOWNORMAL);
而且这个函数还可以指定程序打开一个属于程序本身类型的文件, 假如e盘有一个a.txt文件; 我调用函数运行记事本程序并打开这个文本文件.
ShellExecute(NULL, "open", "NOTEPAD.EXE", "e:\\a.txt", NULL, SW_SHOWNORMAL);
这里由于记事本程序属于系统本身自带的程序, 所以没有绝对路径.
这个函数还可以打开一个网站:
ShellExecute(NULL, "open", "http://www.baidu.com", NULL, NULL, SW_SHOWNORMAL);
ShellExecute(NULL, "open", "C:", NULL, NULL, SW_SHOWNORMAL);


还可以根据文件后缀名选择相应的程序打开一个文件：
ShellExecute(NULL, "open", "e:\\a.bmp", NULL, NULL, SW_SHOWNORMAL);
类似的函数还有WinExec，只有两个参数, 它的最后一个参数跟ShellExecute函数的最后一个参数一样.
而第一个参数则是程序路径名.举个例子:WinExec("NOTEPAD.EXE", SW_SHOWNORMAL);
这个函数也可以给程序传递一个文件名供要运行的程序打开, 那要如何加进去呢, 这里又没有第三个参数,
方法把路径名加在NOTPEPAD.EXE的后面, 要以空格来分开如:
WinExec("NOTEPAD.EXE e:\\a.txt", SW_SHOWNORMAL);


第十九个PlaySound播放一个WAV文件


函数定义：BOOL PlaySound(LPCSTR pszSound, HMODULE hmod, DWORDfdwSound);


第一个参数是WAV文件的路径名，第二个参数如果不是播放MFC里以资源ID命名的文件，则可以为空，第三个参数，指明了以何种方式播放文件。注意这个函数只能播放100K以下的WAV文件。


假如E盘有个a.wav文件，下面这个例子播放这个文件：


#include<windows.h>
#include<mmsystem.h>//PlaySound函数的头文件
#pragma comment(lib, "winmm.lib")//链接库，PlaySound函数必须使用
int main()


{
	PlaySound("e:\\19.wav", NULL, SND_SYNC);
	return 0;
}


第二十个GetModuleFileName根据模块导入表获取程序的完整路径


函数定义：DWORD GetModuleFileName(HMODULE hModule, LPTSTRlpFilename, DWORD nSize);


关于第一个参数，将在以后的动态链接库里会有介绍，这里我们只要获得程序本身的路径，那么第一个参数可以为空。


第二个参数用以存储路径，nSize指明字符数组大小。


这个举个例子，运行后，把自身程序移动到e盘下，并改名为a.exe;


#include<windows.h>


int main()


{


	char szAppName[128] = { 0 };
	GetModuleFileName(NULL, szAppName, 128);


	MoveFile(szAppName, "e:\\a.exe");


	return 0;


}





http://hi.baidu.com/3582077/item/fc3e11164b01c00dd0d66de5


第二十一个CreateWindow创建一个窗口


//补习懂的人直接跳过


之前API函数的例子，都是针对DOS编程的，严格来说是在windows下的仿DOS（cmd)进行编程，编写控制台应用程序大家都知道，主函数是main，那针对windows编程的主函数也是main吗？不是的，windows下的主函数（入口函数）是WinMain。在定义main主函数的时候，可以给它带两个参数，也可以不带。而WinMain函数就不能这样了，它有固定的格式，它必须带四个参数。


现给出WinMain函数的固定格式：


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCEhPrevInstance, LPSTR lpCmdLine, int nCmdShow)


大家如果有兴趣可以通过其它渠道了解一下各参数的意思，现在我们只需要知道WinMain函数就是这样定义的，不理解也没关系。


知道了这个我们就来编一个WINDOWS程序吧！


因为我们是针对windows编程，所以要建一个Win32Application工程，步骤是点击文件，然后选择新建，在弹出的对话框里选择工程，再选中Win32Application 接着在右边的工程名称下填工程名称，名字随便取。之后点确定。接着又弹出了一个对话框，这里为了方便，我们选择“一个简单的 Win32 程序”，点完成。接着双击WinMain弹出代码编辑窗口，做完这个我们就可以打代码了。


简单的例子如下：


#include "stdafx.h"


int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{


	while (1)


		Sleep(100);
	return 0;
}


怎么样够简单吧，是不是觉得奇怪，怎么没有窗口，因为窗口要自己创建，不像控制台程序，只要一运行便会有窗口。虽然没有窗口，但你创建了一个进程，打开任务管理器，可以找到你所创建的那个进程，其实也没什么奇怪的，像WINDOWS本身的一些系统服务，也是只有进程，没有窗口的像spoolsv.exe, svchost.exe。


那要如何创建一个窗口呢？要创建一个窗口, 就必须要向系统提供窗口的信息，如你要创建的窗口名字叫什么，窗口图标是什么，窗口大小，窗口背景色等，不然，系统怎么给你创建窗口呢？所以为了方便，VC就定义了一个结构，专门用于存储窗口信息。


现给出这个结构的定义。


typedef struct _WNDCLASS {
	UINT style; //描述类风格
	WNDPROC lpfnWndProc; //窗口处理函数
	int cbClsExtra; //表示窗口类结构之后分配的额外的字节数。系统将该值初始化为0
	int cbWndExtra; //表示窗口实例之后分配的额外的字节数。系统将该值初始化为0
	HINSTANCE hInstance;// 应用程序实例句柄由WinMain函数传进来 
	HICON hIcon; //窗口图标句柄 
	HCURSOR hCursor; //窗口光标句柄
	HBRUSH hbrBackground; //画刷句柄
	LPCTSTR lpszMenuName; //窗口菜单名
	LPCTSTR lpszClassName; //窗口类名
} WNDCLASS, *PWNDCLASS;


好了，如果我们已经把窗口信息填好了，那我们要怎样把这个信息告诉系统呢，也就是把要创建窗口的信息传给系统。这里我们调用RegisterClass函数就能实现这个功能。注册完窗口，我们就要创建窗口, 用CreateWindow函数就能实现，不要问为什么注册窗口后直接显示不就行了，还要搞什么创建窗口。这我也不知道，反正你只要记住这格式就行了，硬式规定的，你想创建一个窗口，就必须按这些步骤来。


好了，窗口创建了，我们就要调用ShowWindow函数显示窗口，然后用UpdateWindow函数刷新一下，确保窗口能立即显示。


以下详细实现代码：


#include "stdafx.h"
#include<windows.h>
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{


	WNDCLASS wndcls; //定义一个存储窗口信息WNDCLASS变量
	wndcls.cbClsExtra = 0; //默认为0
	wndcls.cbWndExtra = 0; //默认为0
	wndcls.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); //背景画刷
	wndcls.hCursor = LoadCursor(NULL, IDC_CROSS); //十字光标
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR); //窗口图标
	wndcls.hInstance = hInstance; //应用程序实例句柄由WinMain函数传进来 
	wndcls.lpfnWndProc = NULL; //窗口消息处理函数
	wndcls.lpszClassName = "windowclass"; //窗口类名
	wndcls.lpszMenuName = NULL; //窗口菜单名，没有菜单，为NULL
	wndcls.style = CS_HREDRAW | CS_VREDRAW;//窗口类型，CS_HREDRAW和CS_VERDRAW 表明
	//当窗口水平方向垂直方向的宽度变化时重绘整个窗口
	RegisterClass(&wndcls); //把窗口信息提交给系统，注册窗口类
	HWND hwnd; //用以存储CreateWindow函数所创建的窗口句柄
	hwnd = CreateWindow("windowclass", "first windows",
		WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);//创建窗口
	ShowWindow(hwnd, SW_SHOWNORMAL);//窗口创建完了，显示它
	UpdateWindow(hwnd); //更新窗口，让窗口毫无延迟的显示
	return 0;
}


是不是出错了，内存不能读取，为什么了呢，因为你创建的窗口没有消息处理函数，windows系统当然不允许这样一个窗口存在，对按键，鼠标都没有反应，这样的窗口是没有实际意义的。 wndcls.lpfnWndProc = NULL; //窗口消息处理函数，就是前面这句，必须要填
窗口过程（消息）处理函数，那这个函数是怎样定义的呢，像WinMain一样，它也有固定的格式。


窗口过程处理函数的格式：LRESULT CALLBACK WinSunProc(HWND wnd, UINTuMsg, WPARAM wParam, LPARAM lParam)


下面的这个是一个窗口创建的完整例子：


#include "stdafx.h"
#include<windows.h>
LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_LBUTTONDOWN)MessageBox(NULL, "kdjfkdf", "Kjdfkdfj", MB_OK);//处理鼠标按下消息，弹出消息框
	return DefWindowProc(hwnd, uMsg, wParam, lParam); //未处理的消息通过DefWindowProc函数交给系统处理
}
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{


	WNDCLASS wndcls; //定义一个存储窗口信息WNDCLASS变量
	wndcls.cbClsExtra = 0; //默认为0
	wndcls.cbWndExtra = 0; //默认为0
	wndcls.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); //背景画刷
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW); //光标
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR); //窗口图标
	wndcls.hInstance = hInstance; //应用程序实例句柄由WinMain函数传进来 
	wndcls.lpfnWndProc = WinSunProc; //窗口消息处理函数
	wndcls.lpszClassName = "windowclass"; //窗口类名
	wndcls.lpszMenuName = NULL; //窗口菜单名，没有菜单，为NULL
	wndcls.style = CS_HREDRAW | CS_VREDRAW;//窗口类型，CS_HREDRAW和CS_VERDRAW 表明
	//当窗口水平方向垂直方向的宽度变化时重绘整个窗口
	RegisterClass(&wndcls); //把窗口信息提交给系统，注册窗口类
	HWND hwnd; //用以存储CreateWindow函数所创建的窗口句柄
	hwnd = CreateWindow("windowclass", "first windows",
		WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);//创建窗口
	ShowWindow(hwnd, SW_SHOWNORMAL);//窗口创建完了，显示它
	UpdateWindow(hwnd); //更新窗口，让窗口毫无延迟的显示
	MSG msg;//消息结构类型
	while (GetMessage(&msg, NULL, 0, 0))//获取消息
	{
		//TranslateMessage(&msg); //此函数用于把键盘消息(WM_KEYDOWN,WM_KEYUP)转换成字符消息WM_CHAR
		DispatchMessage(&msg); //这个函数调用窗口过程处理函数，并把MSG里的信息处理后传给过程函数的四个参数
	}
	return 0;
}


WinSunProc函数的四个参数，分别对应着SendMessage函数四个参数，详情参见SendMessage函数参数解释。


MSG类型解释 ：


结构定义：


typedef struct tagMSG
{
	HWND hwnd;//hwnd表示消息将要发送给的窗口句柄
	UINT message;//消息类型，如WM_WMCLOSE,WM_CHAR,WM_LBUTTONDOWN,参见消息表
	WPARAM wParam;//消息附带信息，取值的意思具体依据消息类型而定
	LPARAM lParam;//消息附带信息，取值的意思具体依据消息类型而定
	DWORD time;//消息的发送时间，不常用
	POINT pt;//消息发送时，鼠标所在的位置，不常用
}MSG;


大家试着把上面的例子运行一遍，然后关掉窗口，再运行一遍，是不是出错了，因为前一个程序虽然窗口关闭了，但进程还在运行，还记得那个循环语句吗？while(GetMessage(&msg, NULL, 0, 0))就是这个。只要条件成立，进程就会一直运行下去。如何让这个循环结束呢？用 PostQuitMessage(0); 这个语句就行了，参数0表示给自身窗口发送一个退出消息，当GetMessage函数接到PostQuitMessage函数发出的消息后，就会返回0值。


如在窗口过程函数中处理窗口关闭WM_CLOSE消息 : if (uMsg == WM_CLOSE）PostQuitMessage(0); 这样只要一关闭窗口，它的进程也会结束。


	接下来解释一下CreateWindow函数参数的意思, 函数定义


	HWND CreateWindow(LPCTSTR lpClassName,//窗口类名，应与WNDCLASS结构里的成员lpszClassName一致
		LPCTSTR lpWindowName, ,//窗口标题名
		DWORD dwStyle，//窗口的风格，取值参见表Style


		int x,
		int y,//x,y表示所创建窗口左上角位置
		int nWidth,
		int nHeight,//nWidth,nHeight表示窗口的宽高
		HWND hWndParent,//父窗口句柄，如果不是子窗口，这里取值为NULL
		HMENU hMenu,//菜单句柄，没菜单的话，取NULL值
		HANDLE hlnstance,//对应着WinMain函数的第一个参数
		LPVOID lpParam);//NULL


表Style：（参考：百度）


WS_BORDER：创建一个单边框的窗口。
WS_CAPTION：创建一个有标题框的窗口（包括WS_BODER风格）。
WS_CHILD：创建一个子窗口。这个风格不能与WS_POPUP风格合用。
WS_CHLDWINDOW：与WS_CHILD相同。
WS_CLIPCHILDREN : 当在父窗口内绘图时，排除子窗口区域。在创建父窗口时使用这个风格。
	WS_CLlPBLINGS；排除子窗口之间的相对区域，也就是，当一个特定的窗口接收到WM_PAINT消息时，WS_CLIPSIBLINGS 风格将所有层叠窗口排除在绘图之外，只重绘指定的子窗口。如果未指定WS_CLIPSIBLINGS风格，并且子窗口是层叠的，则在重绘子窗口的客户区时，就会重绘邻近的子窗口。
	WS_DISABLED : 创建一个初始状态为禁止的子窗口。一个禁止状态的窗口不能接受来自用户的输入信息.
	WS_DLGFRAME : 创建一个带对话框边框风格的窗口。这种风格的窗口不能带标题条。
	WS_GROUP : 指定一组控制的第一个控制。这个控制组由第一个控制和随后定义的控制组成，自第二个控制开始每个控制，具有WS_GROUP风格，每个组的第一个控制带有WS_TABSTOP风格，从而使用户可以在组间移动。用户随后可以使用光标在组内的控制间改变键盘焦点。　　
	WS_HSCROLL：创建一个有水平滚动条的窗口。
	WS_ICONIC：创建一个初始状态为最小化状态的窗口。
	与WS_MINIMIZE风格相同。
	WS_MAXIMIZE：创建一个初始状态为最大化状态的窗口。
	WS_MAXIMIZEBOX：创建一个具有最大化按钮的窗口。该风格不能与WS_EX_CONTEXTHELP风格同时出现，同时必须指定WS_SYSMENU风格。
	WS_OVERLAPPED : 产生一个层叠的窗口。一个层叠的窗口有一个标题条和一个边框。与WS_TILED风格相同。　　WS_OVERLAPPEDWINDOW：创建一个具有WS_OVERLAPPED，WS_CAPTION，WS_SYSMENU WS_THICKFRAME，WS_MINIMIZEBOX，WS_MAXIMIZEBOX风格的层叠窗口，与WS_TILEDWINDOW风格相同。 　　WS_POPUP；创建一个弹出式窗口。该风格不能与WS_CHLD风格同时使用。
	WS_POPUWINDOW：创建一个具有WS_BORDER，WS_POPUP, WS_SYSMENU风格的窗口，WS_CAPTION和WS_POPUPWINDOW必须同时设定才能使窗口某单可见。　　
	WS_SIZEBOX：创建一个可调边框的窗口，与WS_THICKFRAME风格相同。
	WS_SYSMENU：创建一个在标题条上带有窗口菜单的窗口，必须同时设定WS_CAPTION风格。　　
	WS_TABSTOP：创建一个控制，这个控制在用户按下Tab键时可以获得键盘焦点。按下Tab键后使键盘焦点转移到下一具有WS_TABSTOP风格的控制。
	WS_THICKFRAME：创建一个具有可调边框的窗口，与WS_SIZEBOX风格相同。
	WS_TILED：产生一个层叠的窗口。一个层叠的窗口有一个标题和一个边框。
	与WS_OVERLAPPED风格相同。
	WS_TILEDWINDOW : 创建一个具有WS_OVERLAPPED，WS_CAPTION，WS_SYSMENU， WS_THICKFRAME，WS_MINIMIZEBOX，WS_MAXMIZEBOX风格的层叠窗口。与WS_OVERLAPPEDWINDOW风格相同。　　
	WS_VISIBLE创建一个初始状态为可见的窗口。
	WS_VSCROLL：创建一个有垂直滚动条的窗口。


	第二十二个GetMessage获取窗口消息


	参照CreateWindow函数例子，以后的例子可能是在控制台下，也可能是Win32 Application，大家以后根据主函数判断该建什么工程。


	第二十三个RegisterClass注册窗口类，参照CreateWindow


	第二十四个UpdateWindow参照CreateWindow


	第二十五个DispatchMessage参照CreateWindow


	第二十六个LoadCursorFromFile从磁盘加载一个光标文件，函数返回该光标句柄


	假设e盘下有一个名为a.cur的光标文件。


	HCURSOR cursor//定义一个光标句柄，用于存放LoadCursorFromFile函数返回的光标句柄


	cursor = LoadCursorFromFile("e:\\a.cur");


获得了光标句柄有什么用呢？看一下窗口类WNDCLASS里的hCursor成员，这个成员也是一个光标句柄，明白了吧！


第二十七个CreateSolidBrush创建一个画刷，函数返回画刷句柄


HBRUSH hbr = CreateSolidBrush(RGB(12, 172, 59));//三个数字分别表明RGB的颜色值，RGB根据三种颜色值返回一个COLORREF类型的值


第二十八个LoadImage装载位图、图标、光标函数


函数定义：HANDLE LoadImage(HINSTANCE hinst, LPCTSTR lpszName, UINTuType, int cxDesired, int CyDesired, UINT fuLoad)


这里我们只要这个函数的几个简单功能：从磁盘加载位图，从磁盘加载图标，从磁盘加载光标。所以第一个参数hinst我们不用管它，直接填NULL就行，第二个参数lpszName是图片文件所在路径名，第三个参数uType指明要加载的是什么类型的图片，


是位图（填IMAGE_BITMAP），还是光标（填IMAGE_CURSOR），还是图标（填IMAGE_ICON）。第四个cxDesired和第五个参数CyDesired, 指定要加载的图片的宽高（可以放大光标，或者缩小），如果加载的是位图的话，则两个参数必须为0，第六个参数fuLoad表示以何种方式加载文件，这里我们是从磁盘加载文件，所以填LR_LOADFROMFILE;


好了，假设e盘下有一个c.cur和i.ico文件。例子：设置窗口图标和光标，还有背景色


#include "stdafx.h"//这个头文件是编译器自动生成的，不是空工程，都会有，
//如果是直接建C++源文件，包含这个头文件，会出错


#include <windows.h> 
#include <stdio.h> 
LRESULT CALLBACK WinSunProc(
	HWND hwnd, // handle to window 
	UINT uMsg, // message identifier 
	WPARAM wParam, // first message parameter 
	LPARAM lParam // second message parameter 
); //窗口过程函数声明
int WINAPI WinMain(
	HINSTANCE hInstance, // handle to current instance 
	HINSTANCE hPrevInstance, // handle to previous instance 
	LPSTR lpCmdLine, // command line 
	int nCmdShow // show state 
)
{
	//设计一个窗口类 
	WNDCLASS wndcls;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = CreateSolidBrush(RGB(12, 172, 59));//画刷
	wndcls.hCursor = (HCURSOR)LoadImage(NULL, "e:\\c.cur", IMAGE_CURSOR, 24, 24, LR_LOADFROMFILE);//加载光标
	wndcls.hIcon = (HICON)LoadImage(NULL, "e:\\i.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE);//加载图标
	wndcls.hInstance = hInstance; //应用程序实例句柄由WinMain函数传进来 
	wndcls.lpfnWndProc = WinSunProc; //定义窗口处理函数
	wndcls.lpszClassName = "windowclass";
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls);


	//创建窗口，定义一个变量用来保存成功创建窗口后返回的句柄 
	HWND hwnd;
	hwnd = CreateWindow("windowclass", "first window",
		WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);
	//显示及刷新窗口 
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
	//定义消息结构体，开始消息循环 
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}


//编写窗口过程函数 
LRESULT CALLBACK WinSunProc(
	HWND hwnd, // handle to window 
	UINT uMsg, // message identifier 
	WPARAM wParam, // first message parameter 
	LPARAM lParam // second message parameter 
)
{
	switch (uMsg)
	{
	case WM_CHAR: //字符消息
		char szChar[20];
		sprintf(szChar, "char code is %c", wParam);
		MessageBox(hwnd, szChar, "char", 0);
		break;
	case WM_LBUTTONDOWN: //鼠标左键按下消息
		MessageBox(hwnd, "mouse clicked", "message", 0);
		break;
	case WM_CLOSE:
		if (IDYES == MessageBox(hwnd, "是否真的结束？", "message", MB_YESNO))
		{
			DestroyWindow(hwnd); //销毁窗口，并发送WM_DESTROY消息给自身窗口
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}


第二十九个GetDC根据窗口句柄获取设备上下文（DC）返回DC句柄


得到了一个窗口的设备上下文，就可以进行画图操作了，像画圆，画正方形，显示图片等函数都是要设备上下文(DC）句柄做参数的。


	HDC dc//定义一个DC句柄


	HWND wnd = FindWindow(NULL, "无标题.txt- 记事本");//获取窗口句柄


dc = GetDC(wnd)//获取这个窗口的设备上下文


第三十个Rectnagle在窗口中画一个矩形


以"无标题.txt - 记事本"窗口为例，在这个窗口简单的画一个矩形


#include<windows.h>
void main()
{
	HDC dc;
	HWND wnd = FindWindow(NULL, "无标题.txt - 记事本");
	dc = GetDC(wnd);//获取窗口设备上下文（DC）
	while (1)//用循环语句重复画，是为了确保不会被窗口刷新给刷掉
	{
		Rectangle(dc, 50, 50, 200, 200);//画一个矩形
		Sleep(200);
	}
}





http://hi.baidu.com/3582077/item/535b4211faa5df8f88a956e5


第三十个CreateToolhelp32Snapshot给当前进程拍一个照


HANDLEhProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);


//记住这种格式就行了，返回的句柄，存储有进程信息，可以用Process32Firs函数找出来。


第三十一个Process32First根据CreateToolhelp32Snapshot函数返回的句柄获取进程信息


结合Process32Next函数使用，有点像文件寻找函数。


看完整例子：显示系统进程名，以及进程ID号


#include<windows.h>
#include<tlhelp32.h>//声明快照函数的头文件
#include<stdio.h>
int main()
{
	PROCESSENTRY32 pe32;//进程的信息将会存储在这个结构里
	//在使用这个结构之前，先设置它的大小
	pe32.dwSize = sizeof(pe32);
	//给系统内的所有进程拍一个快照
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);//第一次查找
	while (bMore)
	{
		printf("进程名称:%s\n", pe32.szExeFile);//szExeFile是进程名
		printf("进程ID号:%u\n\n", pe32.th32ProcessID);//th32ProcessID是进程ID号
		bMore = ::Process32Next(hProcessSnap, &pe32);//寻找下个进程，函数返回0，则没有进程可寻
	}
	return 0;
}


第三十二个OpenProcess根据进程ID号获得进程句柄，句柄通过函数返回


函数定义：HANDLE OpenProcess(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId);


第一个参数不要管它，填PROCESS_ALL_ACCESS，第二个参数也一样，填FALSE，那最后一个参数就是进程ID号。


第三十三个TerminateProcess结束一个进程（需进程句柄做参数）


该函数只有两个参数，第一个是进程句柄，第二个填0就行了。


现在给个例子：假设当前有一个进程名为abc.exe的进程正在运行，编一个程序结束它。


#include<windows.h>
#include<tlhelp32.h>//声明快照函数的头文件
int main(int argc, char *argv[])
{




	PROCESSENTRY32 pe32;
	//在使用这个结构之前，先设置它的大小
	pe32.dwSize = sizeof(pe32);
	//给系统内的所有进程拍一个快照
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	//遍历进程快照，轮流显示每个进程的信息
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
	while (bMore)
	{


		if (strcmp("abc.exe", pe32.szExeFile) == 0)//如果找到进程名为abc.exe
		{
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);//获取句柄
			::TerminateProcess(hProcess, 0);//结束它
		}
		bMore = ::Process32Next(hProcessSnap, &pe32);//寻找下一个
	}
	return 0;
}


上面的这个例子，只能结束普通权限进程，如果为系统进程的话，则没有用，结束不了。在后面的提升权限函数，会有例子说明如何结束系统进程。


第三十四个CreatePen创建一个画笔（返回画笔句柄）


函数定义：BOOL CreatePen(int nPenStyle, int nWidth, COLORREFcrColor);


第一个参数，表示是什么类型的线，取值有以下：


PS_SOLID 画笔画出的是实线 PS_DASH 画笔画出的是虚线（nWidth必须是1） PS_DOT 画笔画出的是点线（nWidth必须是1）
PS_DASHDOT 画笔画出的是点划线（nWidth必须是1） PS_DASHDOTDOT 画笔画出的是点 - 点 - 划线（nWidth必须是1）
第二个参数是画笔的宽度，第三个参数是画笔的颜色，COLORREF类型可以RGB来获得如RGB(233, 128, 88); 分别是红绿蓝。


如创建一个画笔：HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 78, 99));


第三十五个CreateSolidBrush创建一个画刷


只有一个COLORREF类型的参数


HBRUSH brush = CreateSolidBrush(RGB(22, 182, 111));


第三十六个SelectObject把GDI对象选入相应的DC中


像画笔(句柄HPEN），画刷（HBURSH），位图（HBITMAP）等都是GID对象。因为画图函数，如画圆，画矩形，画直线，它们所画出图形，默认属性都是不变的，如线的宽度。那么想要改变画出来时线的宽度，比如我想画出来的图形它的线条宽度为5（像素），那么就要创建一个宽度为5的画笔，然后再通过SelectObject函数，给这个画笔选入，就可以了.


	接下举个例子:SelectObject应用




#include "stdafx.h"
#include<windows.h>
	LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 78, 99));//创建画笔
	static HBRUSH brush = CreateSolidBrush(RGB(22, 182, 111));//创建画刷
	if (uMsg == WM_PAINT)//窗口需要重画的时候
	{
		HDC hDC;
		PAINTSTRUCT ps;
		hDC = BeginPaint(hwnd, &ps); //BeginPaint只能在响应WM_PAINT,不能用GetDC获取设备上下文
		SelectObject(hDC, pen);//选入画笔
		SelectObject(hDC, brush);//选入画刷
		Rectangle(hDC, 100, 100, 200, 200);
		EndPaint(hwnd, &ps);
	}
	else if (uMsg == WM_CLOSE)//用户关闭了窗口
		DestroyWindow(hwnd);//销毁窗口，并发送WM_DESTROY消息
	else if (uMsg == WM_DESTROY)//如果窗口被销毁
		PostQuitMessage(0);//让进程退出
	return DefWindowProc(hwnd, uMsg, wParam, lParam); //未处理的消息通过DefWindowProc函数交给系统处理
}
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{


	WNDCLASS wndcls; //定义一个存储窗口信息WNDCLASS变量
	wndcls.cbClsExtra = 0; //默认为0
	wndcls.cbWndExtra = 0; //默认为0
	wndcls.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); //背景画刷
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW); //光标
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR); //窗口图标
	wndcls.hInstance = hInstance; //应用程序实例句柄由WinMain函数传进来 
	wndcls.lpfnWndProc = WinSunProc; //窗口消息处理函数
	wndcls.lpszClassName = "windowclass"; //窗口类名
	wndcls.lpszMenuName = NULL; //窗口菜单名，没有菜单，为NULL
	wndcls.style = CS_HREDRAW | CS_VREDRAW;//窗口类型，CS_HREDRAW和CS_VERDRAW 表明
	//当窗口水平方向垂直方向的宽度变化时重绘整个窗口
	RegisterClass(&wndcls); //把窗口信息提交给系统，注册窗口类
	HWND hwnd; //用以存储CreateWindow函数所创建的窗口句柄
	hwnd = CreateWindow("windowclass", "first windows",
		WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);//创建窗口
	ShowWindow(hwnd, SW_SHOWNORMAL);//窗口创建完了，显示它
	UpdateWindow(hwnd); //更新窗口，让窗口毫无延迟的显示
	MSG msg;//消息结构类型
	while (GetMessage(&msg, NULL, 0, 0))//获取消息
	{
		//TranslateMessage(&msg); //此函数用于把键盘消息(WM_KEYDOWN,WM_KEYUP)转换成字符消息WM_CHAR
		DispatchMessage(&msg); //这个函数调用窗口过程处理函数，并把MSG里的信息处理后传给过程函数的四个参数
	}
	return 0;
}


第三十七个 ReadProcessMemory根据进程句柄读取相应的一段内存（读其它进程里的内存）


函数定义：BOOL ReadProcessMemory(HANDLE hProcess, PVOIDpvAddressRemote, PVOID pvBufferLocal, DWORD dwSize,


	PDWORD pdwNumBytesRead); 总共四个参数


	第一个参数hProcess是远程进程句柄，被读取者 。第二个pvAddressRemote是远程进程中内存地址。 从具体何处读取


	pvBufferLocal是本地进程中内存地址.函数将读取的内容写入此处，dwSize是要读取的字节数。要读取多少


	pdwNumBytesRead是实际读取的内容（函数执行后，实际读了多少字节，将存储在该变量里）


	远程进程的内存地址是什么意思呢，比如我现在定义一个变量a, int a; 就是了，大家知道int型是占四个字节的，也就是说如果a变量所占的内存起始地址是0x1234, 那么变量a就占用0x1234, 0x1235, 0x1236, 0x1237这四个字节，这四个字节的内容决定了a变量的值。


	好了知道了这个，我们就来举个例子，读取另一个进程里一个变量的值：需设计两个程序，一个用于读（Read)一个用于被读(BeRead);


那么要如何获得另一个进程中一个变量的地址呢 ? 这里我们用一个简单的方法，让另一个进程自己去获取，然后输出地址值。


被读的程序代码如下：假设该进程名为：BeRead.exe
#include<stdio.h>
int main()
{
	int a = 10;//要读取的变量。
	printf("%x\n", &a);//输出这个变量的起始地址，假设输出为12ff7c
	while (1)
	{
		Sleep(1000);
	}


	return 0;
}


必须先让这个程序运行，然后根据输出的地址值，才能在下面的程序填入地址值。


读取的程序代码如下：


#include<windows.h>
#include<stdio.h>
#include<tlhelp32.h>
int main()
{


	//先要获取进程句柄，如何获取，参照TerminateProcess函数，结束一个进程


	HANDLE ReProcess;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
	while (bMore)
	{
		if (strcmp(pe32.szExeFile, "BeRead.exe") == 0)//如果是BeRead.exe
		{
			ReProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);//获取该进程句柄
			break;
		}
		bMore = Process32Next(hProcessSnap, &pe32);
	}
	int *ReAddress = (int *)0x12ff7c;//要读取的内存的地址值
	int *p = new int;
	unsigned long size;
	ReadProcessMemory(ReProcess, ReAddress, p, 4, &size);//读取BeRead进程的内存
	printf("%d\n", *p);//输出读取来的值
	return 0;
}


第三十八个WriteProcessMemory根据进程句柄写入相应的一段内存（写入其它进程里的内存）


这个函数里的参数跟ReadProcessMemory函数参数意思一样，只不过一个是写，一个是读。


下面直接举个例子，形式跟读内存函数的例子一样。


被写的程序代码如下：假设该进程名为：BeWrite.exe


#include<stdio.h>
int main()
{
	int a = 10;
	printf("%x\n", &a);//假设输出为12ff7c
	while (1)
	{
		printf("%d\n", a);//每隔一秒输出，查看值有没有改变
		Sleep(1000);
	}


	return 0;
}


写入的代码如下：


#include<windows.h>
#include<stdio.h>
#include<tlhelp32.h>
int main()
{
	HANDLE ReProcess;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
	while (bMore)
	{
		if (strcmp(pe32.szExeFile, "BeWrite.exe") == 0)
		{
			ReProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
			break;
		}
		bMore = Process32Next(hProcessSnap, &pe32);
	}
	int *ReAddress = (int *)0x12ff7c;
	int *p = new int;
	*p = 300;
	unsigned long size;
	WriteProcessMemory(ReProcess, ReAddress, p, 4, &size);


	return 0;
}


第三十九个CreateThread创建一个线程（多线程）


线程是什么意思呢，代码是由线程来执行的，一个程序默认只有一个线程（主线程），打个比方，线程就好比一个人，而不同功能的代码或函数就好是一件件不同的事情，如洗碗，洗衣服，擦地。一个人要把这几种事情做完，可以有好几种方案，第一种就是，洗完碗，就去洗衣服，衣服洗完了，再去擦地。第二种就是：洗一分钟碗，再去洗一分钟衣服，再去擦一分钟，然后又去洗一分钟衣服.......直到做完。好了，现在你可以再创造一个人帮你做事，创造这个人后，你就叫他洗衣服，而你就洗碗，这样两件事就可以同时被做了。而这里的创造一个人指的就是CreateThread函数。


函数定义：HANDLE CreateThread(LPSECURITY_ATTRIBUTESlpThreadAttributes, DWORD dwStackSize, LPTHREAD_START_ROUTINElpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);


该函数有六个参数，第一个参数不用管它，填NULL，第二个参数dwStackSize用于新线程的初始堆栈大小，默认为0，第三个lpStartAddress填函数名（指标），但这个函数必须是这种固定格式的DWORD _stdcall ThreadProc(LPVOID lpParameter), 新的线程将会执行这个函数里面的代码，直到函数结束，线程死亡。第四个lpParameter是一自定义参数，用户可以通过这个参数，传递需要的类型，这个参数与线程函数的参数相对应。第五个dwCreationFlags填0表示立即执行，如果是CREATE_SUSPENDED表示挂起，直到用ResumeThread函数唤醒。第六个lpThreadId填NULL就行了。


现举个例子，两个线程同时每隔一秒输出一个数字，也就是一秒会有两数字输出。


#include<windows.h>
#include<stdio.h>
DWORD _stdcall ThreadProc(LPVOID lpParameter)//线程执行函数
{
	int si = 100;
	while (si > 0)
	{
		printf("子线程输出数字:%d\n", si--);
		Sleep(1000);
	}
	return 0;
}


int main()
{
	int mi = 0;
	CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);//创建一个线程，去执行ThreadProc函数
	while (mi < 100)
	{
		printf("主线程输出数字:%d\n", mi++);
		Sleep(1000);
	}
	return 0;
}


第四十个GetCurrentProcessId获得当前进程ID


DWORD currentPID;
currentPID = ::GetCurrentProcessId();//返回进程ID号
cout << currentPID << endl;





http://hi.baidu.com/3582077/item/1e77f39fbee5b1de1f4271e3


第四十一个CreateCompatibleDC创建一个兼容的内存设备上下文（DC）


根据DC创造一个兼容的内存DC，此时创造出来的内存DC仅仅是一些属性跟源DC一样，如DC的大小，以及对应窗口的宽高等。内存DC里的数据没有具体取值，需用其它函数给里面的数据赋值。


第四十二个GetObject获取一个对象信息（如位图，图标，光标）


函数定义：int GetObject(HGDIOBJ hgdiobj, int cbBuffer, LPVOIDlpvObject)；


第一个参数hgdiobj是对象句柄，第二个参数cbBuffer是待写入lpvObject指针指向缓存区数据大小，第三个参数lpvObject是一个指针，指向一个缓存区。


这里举一个获取位图的信息，获取位图的大小，假设E盘下有一个aa.bmp的位图文件，输出位图的宽高


#include<windows.h>
#include<stdio.h>
int main()
{
	BITMAP bmInfo;//这个结构存储位图信息
	HBITMAP bmp;
	bmp = (HBITMAP)LoadImage(NULL, "e:\\aa.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	GetObject(bmp, sizeof(BITMAP), &bmInfo);
	printf("位图宽：%d,位图高：%d\n", bmInfo.bmWidth, bmInfo.bmHeight);
	return 0;
}


第四十三个BitBlt在窗口输出一个位图


其实倒不如说这个BitBlt函数是拷贝一个设备上下文（DC），或者合并两个窗口，再延伸一下，合并两个图片？也并无不可，往大了说，窗口难道不是图片吗？用截屏软件，把窗口截成图片，这样窗口便成了图片。可能有点瞎说，大家还是按照标准来吧，反正，你只要掌握这个函数就行了，而且这个概念也不会有什么影响，那就足够了。


BitBlt的作用跟把两幅图片合在一起一样，合并两幅图片。可能两幅图片大小不一样也可以合并，但合并DC就不行了，必须两个信息一样的DC才可以合并，那要如何确保两个DC一样呢？这就要用到CreateCompatibleDC函数了。


函数定义：BOOL BitBlt(HDC hdcDest, int nXDest, int nYDest, intnWidth, int nHeight, HDC hdcSrc, int nXSrc, int nYSrc, DWORD dwRop)；


第一个参数hdcDest是原DC句柄，被覆盖的DC，nXdest, nYDest, nWidth, nHeight这四个参数，指明了一个矩形，覆盖原DC哪块区域。


第六个参数hdcSrc是覆盖的DC句柄，nXSrc, nYSrc参数指明从哪里开始覆盖。（覆盖DC的左上角），第九个参数dwPop表示以何种方式覆盖。因为这里我们只要输出一个位图，所以用SRCCOPY, 直接覆盖。


好了，直接举个例子，在窗口输出一副图片，假设e盘下有一个aa.bmp的位图。为了方便，我们直接在记事本窗口输出位图，先运行一个窗口名为"无标题.txt - 记事本"记事本窗口程序。


#include<windows.h>
#include<stdio.h>
int main()
{
	BITMAP bmInfo;//这个结构存储位图信息
	HBITMAP bmp;
	bmp = (HBITMAP)LoadImage(NULL, "e:\\aa.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	GetObject(bmp, sizeof(BITMAP), &bmInfo);//获取位图信息
	HWND wnd = FindWindow(NULL, "无标题.txt - 记事本");
	HDC hdc = GetDC(wnd);
	HDC memDC = ::CreateCompatibleDC(hdc);//创造兼容的DC
	SelectObject(memDC, bmp);//选入位图
	while (1)
	{


		BitBlt(hdc, 0, 0, bmInfo.bmWidth, bmInfo.bmHeight, memDC, 0, 0, SRCCOPY);//输出位图
		Sleep(200);


	}
	return 0;


}


下面介绍一下BitBlt函数最后一个参数的常用取值及意思。


参考（百度）
BLACKNESS：表示使用与物理调色板的索引0相关的色彩来填充目标矩形区域，（对缺省的物理调色板而言，该颜色为黑色）。　　
DSTINVERT：表示使目标矩形区域颜色取反。
MERGECOPY：表示使用布尔型的AND（与）操作符将源矩形区域的颜色与特定模式组合一起。 　　MERGEPAINT：通过使用布尔型的OR（或）操作符将反向的源矩形区域的颜色与目标矩形区域的颜色合并。 NOTSRCCOPY：将源矩形区域颜色取反，于拷贝到目标矩形区域。
NOTSRCERASE：使用布尔类型的OR（或）操作符组合源和目标矩形区域的颜色值，然后将合成的颜色取反。 PATCOPY：将特定的模式拷贝到目标位图上。
PATPAINT：通过使用布尔OR（或）操作符将源矩形区域取反后的颜色值与特定模式的颜色合并。然后使用OR（或）操作符将该操作的结果与目标矩形区域内的颜色合并。
PATINVERT：通过使用XOR（异或）操作符将源和目标矩形区域内的颜色合并。
SRCAND：通过使用AND（与）操作符来将源和目标矩形区域内的颜色合并。
SRCCOPY：将源矩形区域直接拷贝到目标矩形区域。
SRCERASE：通过使用AND（与）操作符将目标矩形区域颜色取反后与源矩形区域的颜色值合并。 　　SRCINVERT：通过使用布尔型的XOR（异或）操作符将源和目标矩形区域的颜色合并。　　
SRCPAINT：通过使用布尔型的OR（或）操作符将源和目标矩形区域的颜色合并。
WHITENESS：使用与物理调色板中索引1有关的颜色填充目标矩形区域。（对于缺省物理调色板来说，这个颜色就是白色）


第四十四个GetWindowText根据窗口句柄获得窗口标题名


函数定义：int GetWindowText(HWND hWnd, LPTSTR lpString, intnMaxCount);


第一个参数hWnd是要获取窗口标题名的窗口句柄，第二个lpString是个字符串，窗口标题名，将会存储在这里面，第三个参数nMaxCount指明了第二个参数字符数组的大小。


下面结合GetCursorPos和WindowFromPoint举个例子，鼠标指向哪个窗口，就在界面显示那窗口的标题名


#include<windows.h>
#include<stdio.h>
int main()
{
	char Text[256] = { 0 };
	HWND wnd;
	POINT curpos;
	while (1)
	{
		GetCursorPos(&curpos);
		wnd = WindowFromPoint(curpos);
		GetWindowText(wnd, Text, 256);
		printf("%s\n", Text);
		Sleep(300);
	}


	return 0;
}


第四十五个SetWindowText根据窗口句柄设置窗口标题名


这个函数有两个参数，一个是窗口句柄，一个是标题名，这里就不需要解释了吧，直接看例子，设置一个窗口标题名，依旧以


"无标题.txt - 记事本"为例。


#include<windows.h>
#include<stdio.h>
int main(int argc, char* argv[])
{
	HWND wnd;
	wnd = FindWindow(NULL, "无标题.txt - 记事本");//获取窗口句柄
	SetWindowText(wnd, "新的窗口标题");//设置窗口标题名
	return 0;
}


第四十六个GetCurrentProcess获得当前线程句柄


没有参数，直接调用即可，该函数返回线程句柄


第四十七个OpenProcessToken获得一个进程的访问令牌句柄


获得一个进程的访问令牌有什么用呢？主要是为了修改它的权限，前面在介绍结束一个进程的时候说过了，无法结束系统进程，是什么原因呢，原因是调用OpenProcess函数失败，无法获取系统进程句柄而引起的，那为什么会失败呢，权限不够，普通程序的进程没有SeDeDebug权限，而一个进程的权限是与访问令牌相关的，这样我们只要获取一个进程的访问令牌句柄，再以这个句柄为参数调用相应的函数提升进程的权限为SeDeDebug就可以获取系统进程句柄，进而结束它。


函数定义：BOOL OpenProcessToken(HANDLE ProcessHandle, DWORDDesiredAccess, PHANDLE TokenHandle)


第一个参数ProcessHandle待获取的进程句柄，第二个参数DesiredAccess操作类型，填TOKEN_ADJUST_PRIVILEGES就行了，


第三个TokenHandle是访问令牌句柄的指针，该参数接收句柄。


如获得本进程的访问令牌句柄：HANDLE hToken;


OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);


第四十七个LookupPrivilegeValue函数查看对应系统权限的特权值，返回信息到一个LUID结构体里
上面讲过了，进程有权限一说，那么大家也能猜到，进程权限的信息也一定存储在一个结构体里，这个结构体描述了进程权限相关的一些信息。这个结构体在这里就不具体描述了，我们所要做的，只是把一个进程权限设置成SeDeDebug就行了，所以我们只要知道TOKEN_PRIVILEGES便是描述进程权限的结构体就可以了。而LookupPrivilegeValue函数是根据访问令牌句获取相应的权限信息吗？
不是的。TOKEN_PRIVILEGES结构里的Privileges[0].Luid跟这个函数所查询的东西相对应，也就是说，如果进程是SeDeDeBug权限，那Privileges[0].Luid的取值是怎样的呢？用LookupPrivilegeValue函数便可以获取其取值。
这个函数是这样定义的：BOOL LookupPrivilegeValue(LPCTSTRlpSystemName, LPCTSTR lpName, PLUID lpLuid);
第一个参数lpSystemName通常都填NULL，本地系统调用，第二个参数lpName填要查询的权限名，如要查询的是SeDeDebug权限则取值是SE_DEBUG_NAME，第三个参数lpLuid接收其取值。
如LUIDluid; LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid);


第四十八个AdjustTokenPrivileges调整一个进程的访问令牌信息（权限）


函数定义：BOOL AdjustTokenPrivileges(HANDLE TokenHandle, BOOLDisableAllPrivileges, PTOKEN_PRIVILEGES NewState, DWORDBufferLength, PTOKEN_PRIVILEGES PreviousState, PDWORD ReturnLength)


第一个参数TokenHandle是令牌句柄，第二个是禁用所有权限标志，后面填FALSE就行了。第三个NewState是待刷进令牌句柄的PTOKEN_PRIVILEGES结构信息指针，第四个BufferLength指明TOKEN_PRIVILEGES结构大小，第五，六个参数填NULL就行了。


那么结合上面两个函数，提升一个进程权限制，让它能够结束系统进程的代码就是：


HANDLE hToken;
OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);
TOKEN_PRIVILEGES tp;
LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
tp.PrivilegeCount = 1;//tp里其它一些属性设置
tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), NULL, NULL);


只要把上面的代码，加入结束普通进程例子的前面，那么就能结束系统进程了。


第四十九个LoadLibrary加载动态链接库，返回动态链接库模块句柄


该函数只有一个参数，那就是动态链接库的名称，如user32.dll，函数返回HMOUDLE类型的模块句柄，获得了一个动态链接库的模块句柄，就可以调用GetProcAddress函数获得模块里面的函数地址，从而调用动态链接库里的函数。


第五十个GetProcAddress根据模块句柄获取相应的函数地址


提到GetProcAddress函数，不得不讲一下怎么设计一个动态链接库，这里我们就以自己设计动态链接库作为GetProcAddress函数的例子。


动态链接库里的函数相对于头文件的函数有什么优势呢？更节省内存，相对于比较常用的函数而已。如果在一个程序里，调用一个头文件里的函数的话，那不管如何，函数的代码就会被复制一份到当前程序里，所以，当有十几个程序调用同一个函数的时候，这个函数在内存中所占用的空间，就会有十几份，分别在各自调用的进程内存空间里，而动态链接库的函数，只在内存中有一份空间（公用空间）如果哪个程序要用到这个函数的话，只要给这个函数的地址，进程就可以跑到这个空间执行函数，那么如何获取函数地址呢，用GetProcAddress函数就行了。


下面我们就自己设计一个动态链接库，点“文件->新建->工程",然后选中“Win32Dynamic-Link Library”,再在右边给工程取一个名，点确定。接着弹出了一个对话框，询问希望创建什么类型，我们选择第二个“一个简单的DLL工程”，点完成->确定.然后单击右边的“+”号，很小的一个，接着下面会出现一个Globals的" + "号，单击该加号，然后再双击DllMain函数，进入代码编辑区，在这里编写代码，这里已经有了一些代码了，编译器自动生成的。那个DllMain函数，便是动态链接库的主函数。在程序进程加载动态链接的时候，进程会自动调用DllMain函数，也就是说会自动执行DllMain函数里的代码，也就是说，如果哪程序执行了这个语句“LoadLibrar("user32.dll")", 那么执行这个语句的进程，便会自动执行user32.dll里的DllMain函数。如果是主线程加载动态库的话，那么该DllMain函数里的代码会被执行两次，分别是加载的时候执行一次，调用FreeLibrary函数释放或程序结束自动释放动态链接库的时候执行一次，至于是什么原因导致DllMain函数被调用，DllMain函数的第二个参数ul_reason_for_call说明了原因，它有四个取值，代表了四个原因。分别是：


DLL_PROCESS_ATTACH（进程加载），DLL_THREAD_ATTACH（线程加载）


DLL_THREAD_DETACH（线程释放），DLL_PROCESS_DETACH（进程释放）


因为这里我们只要设计一个动态链接函数，所以便不用管DllMain函数，DllMain函数将会在介绍CreateRemoteThread（创建一个远程线程）函数的时候讲到，所以我们只要在DllMain函数外定义一个函数就行了。


那么在动态链接库是如何定义函数呢？如果函数不需要导出的话，则跟普通函数定义没什么两样，导出是什么意思，就是可以用GetProcAddress函数获取地址的函数。那导出的函数要如何定义呢？
只要在函数前面加上extern "C" __declspec(dllexport)就行了，声明导出函数，防止函数重命名。那么接下来就举个例子。


动态链接里的代码：


#include "stdafx.h"


BOOL APIENTRY DllMain(HANDLE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved
)
{
	return TRUE;
}
extern "C" __declspec(dllexport) int Add(int a, int b)
{
	return a + b;
}


点编译执行，然后就会弹出一个调试对话框，直接点取消，接着便生成了动态链接库DLL，然后到你的工程里把后缀名为dll的文件找到，


位置在MyProject\"你的工程名"\Debug下。接着把这个文件复制到要调用的工程下，或者直接复制C:\windows\system32目录下。


假设这个文件名为"sss.dll", 那么要调用里面的Add函数便是如下代码：


HMODULE hmod = ::LoadLibrary("sss.dll");//获取sss.dll的模块，加载sss.dll动态链接库
typedef int(*pAdd)(int a, int b);//定义一个对应的函数类型型，以便定义和转换
pAdd add = (pAdd)GetProcAddress(hmod, "Add");//获取hmod模块里的Add函数地址
int a = add(3, 5);//调用模块里的Add函数





http://hi.baidu.com/3582077/item/9c29483b581f53c5392ffa19


第五十一个SetWindowsHookEx安装一个钩子


WINDOWS是基于消息的系统，鼠标移动，单击，键盘按键，窗口关闭等都会产生相应的消息，那么钩子是什么意思呢，它可以监控一个消息，比如在一个窗口里单击了一下，首先获得这个消息的，不是应用程序，而是系统，系统获取这个消息后，就去查看这个消息是在哪个窗口产生的，找到窗口后，再把消息投递到相应程序里的消息队列里，这之间有一个传递过程，那么钩子的作用就是在消息到达应用程序之前截获它，钩子可以关联一个函数（钩子处理函数），也就是说，如果对一个进程安装了一个钩子，进程再接收到相应在消息之前，会先去执行钩子所关联的函数，


先来看一下这个函数定义：


HHOOK WINAPI SetWindowsHookEx(int idHook, HOOKPROClpfn, HINSTANCE hmod, DWORD dwThreadId)


第一个参数idHook指明要安装的钩子类型，如WH_KEYBOARD(键盘钩子），WH_MOUSE(鼠标钩子），第二个参数是钩子处理函数的地址，该函数必须是这种固定的格式：LRESULT WINAPI HookProc(int nCode, WPARAM wParam, LPARAM lParam)


	第三个参数hmod是钩子函数所在模块的句柄，第四个参数dwThreadId是线程ID，待监视消息的ID，如果为0，则为全局钩子，监视所有消息


	好，接下来我们举一个例子，钩子类型为WH_KEYBOARD, 全局钩子。截获键盘按键消息，并扔掉该消息，让键盘失灵。


	由于是装的是全局钩子，所以钩子处理函数必须放在动态链接库里。那么我们就设计一个动态链接库吧。


	现给出动态链接库的所有代码：(KeyDll.dll)


#include "stdafx.h"
#include<windows.h>
	BOOL APIENTRY DllMain(HANDLE hModule,
		DWORD ul_reason_for_call,
		LPVOID lpReserved
	)
{
	return TRUE;
}
HMODULE WINAPI ModuleFromAddress(PVOID pv)//该函数根据内存地址，获得其所在的模块句柄
{
	MEMORY_BASIC_INFORMATION mbi;
	VirtualQuery(pv, &mbi, sizeof(mbi));
	return (HMODULE)mbi.AllocationBase;
}
LRESULT CALLBACK HookKey(int nCode, WPARAM wParam, LPARAM lParam)
{
	return TRUE;//返回真，扔掉该消息
}
extern "C" __declspec(dllexport) void SetHook(void)
{
	SetWindowsHookEx(WH_KEYBOARD, HookKey, ModuleFromAddress(HookKey), 0);
}


生成dll文件后，把它复制到相应的目录下去。


再新建一个工程，调用用动态链接库里的函数，代码如下：


#include<windows.h>
int main()
{
	HMODULE hMod = LoadLibrary("KeyDll.dll");
	typedef void(*pSetHook)(void);
	pSetHook SetHook = (pSetHook)GetProcAddress(hMod, "SetHook");
	SetHook();
	while (1)
	{
		Sleep(1000);//避免程序结束，自动释放动态链接库
	}
	return 0;
}


这样当按下了一个键后，接收该按键消息的进程，会先去执行钩子处理函数，然后再处理消息，而钩子处理函数的几个参数说明了按键的详细信息，如按了哪个键，是按下（KEYDOWN）还是松开（KEYUP）。如果有兴趣的话，把上面那钩子处理函数的代码换成下面这个


LRESULT CALLBACK HookKey(int nCode, WPARAM wParam, LPARAMlParam)
{
	char sz[25];
	sprintf(sz, "%c", wParam);//这个函数头文件#include<stdio.h>
	MessageBox(NULL, sz, sz, MB_OK);
	return FALSE;
}


每按下一个键，就会弹出一个提示框，并输出所按下的键，只对字符键有用。


第五十二个SHGetFileInfo获取一个文件的各项信息（文件关联图标，属性等）
函数定义： DWORD SHGetFileInfo(LPCSTR pszPath, DWORDdwFileAttributes, SHFILEINFOA FAR *psfi, UINT cbFileInfo, UINT uFlags);
pszPath是文件的路径，dwFileAttributes一般取0，如果想要获取文件夹信息的话，则取值为FILE_ATTRIBUTE_DIRECTORY，psfi是一个SHFILEINFO结构的指针，该结构存储文件信息，定义如下：
typedef struct _SHFILEINFOA
{
	HICON hIcon; // 文件关联图标句柄
	int iIcon; // 系统图标列表索引
	DWORD dwAttributes; // 文件的属性
	CHAR szDisplayName[MAX_PATH]; // 文件的路径名
	CHAR szTypeName[80]; // 文件的类型名，如是bmp文件，还是执行文件exe，或者其它
} SHFILEINFO;
第四个参数cbFileInfo指明SHFILEINFO结构的大小，填sizoef(SHFILEINFO);
最后一个参数uFlags指定获取文件的什么信息，可选取值如下：（对应着SHFILEINFO里的成员）
SHGFI_ICON; //获得图标
SHGFI_DISPLAYNAME; //获得显示名
SHGFI_TYPENAME; //获得类型名
SHGFI_USEFILEATTRIBUTES; //获得属性
SHGFI_LARGEICON; //获得大图标
SHGFI_SMALLICON; //获得小图标
SHGFI_PIDL; // pszPath是一个标识符
比如，我只要获取文件图标，那么参数填SHGFI_LARGEICON就行了。如果又想获取文件关联的图标，又想获取文件类型名，那么就是
SHGFI_LARGEICON | SHGFI_TYPENAME;
函数例子：
SHFILEINFO sfi;
SHGetFileInfo("e:\\aa.bmp", 0, &sfi, sizeof(sfi),
	SHGFI_ICON | SHGFI_LARGEICON | SHGFI_USEFILEATTRIBUTES | SHGFI_TYPENAME);


接着可以用DrawIcon函数画出文件关联图标：该函数定义：BOOLDrawIcon（HDC hDC，int X，int Y, HICON hlcon);


第五十三个RegCreateKeyEx在注册表里创建一个子键，或获取一个子键的句柄
在这里我们先来了解一下注册表的基本概念，打开运行对话框，输入regedit，然后回车，便打开了注册表编辑器，首先映入眼前的，便是五个根键
HKEY_CLASSES_ROOT
HKEY_CURRENT_USER
HKEY_LOCAL_MACHINE
HKEY_USER
HKEY_CURRENT_CONFIG


在根键下面便是主键了，如HKEY_CURRENT_CONFIG根键下有两个主键，分别是Software和System（可能会不一样）, 那么主键下面是什么呢，对了，就是跟 RegCreateKeyEx函数相关的子键，子键下面就是具体的键值项了，但也可以又是子键。键值有五种可选类型，分别是：字符串值（REG_SZ)，二进制值（REG_BINARY），DWORD值（REG_DWORD），多字符串值（REG_MULTI_SZ）和可扩充字符值（REG_EXPAND_SZ）。键值项还有其它信息，它的名称，数据。


了解了上面这些东西，接着就来了解下RegCreateKeyEx函数的各个参数吧, 先来看一下函数定义：


LONG RegCreateKeyEx(


	HKEY hKey,//根键句柄，指明要在哪个根键下创建子键，填根键名既可
	LPCSTR lpSubKey,//子键名，包含完整路径名
	DWORD Reserved, .//一般取0
	LPSTR lpClass,//一般取NULL
	DWORD dwOptions,//创建子键时的选项,可选值REG_OPTION_NON_VOLATILE，REG_OPTION_VOLATILE，这里取0既可
	REGSAM samDesired,//打开方式，填KEY_ALL_ACCESS，在任何情况都行。
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,//指定继承性,还是取0
	PHKEY phkResult,//子键对应句柄，待创建或打开的子键句柄将存储在该句柄里
	LPDWORD lpdwDisposition//打开还是创建子键,对应REG_CREATED_NEW_KEY和REG_OPENED_EXISTING_KEY
);


在这里举一个例子，以便我们能更好的理解该函数。


在HKEY_CURRENT_CONFIG根键下的Software主键里创建一个名为MySelf的子键。


#include<windows.h>
int main()
{
	HKEY hroot;//子键句柄
	DWORD dwDisposition;//对应着最后一个参数
	RegCreateKeyEx(HKEY_CURRENT_CONFIG, "Software\\MySelf", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hroot, &dwDisposition);
	return 0;
}


第五十四个RegSetValueEx根据子键句柄在其下创建或修改一个键值


函数定义：LONG RegSetValueEx(
	HKEY hKey, // 子键句柄
	LPCTSTR lpValueName, // 键值名称，如果提供的子键下没有该名称，则创建
	DWORD Reserved, // 保留，填0
	DWORD dwType, // 键值类型，
	CONST BYTE *lpData, // 键值的数据
	DWORD cbData // 键值的数据的大小
);


接着我们以增加开机自启动为例，来看一下函数是如何创建一个键值的，我们知道，像程序添加开机自启动一般都在


HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run下添加一个键值，键值类型为二进制（REG_SZ），而键值的数据就为要自启动程序的路径。


假设e盘下有一个AutoRun.exe的应用程序，让电脑开机时自动运行它。


#include<windows.h>
int main()
{
	HKEY hroot;//子键句柄
	DWORD dwDisposition;
	RegCreateKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0,
		NULL, 0, KEY_ALL_ACCESS, NULL, &hroot, &dwDisposition);
	RegSetValueEx(hroot, "AutoRun", 0, REG_SZ, (BYTE*)"e:\\AutoRun.exe", sizeof("e:\\AutoRun.exe"));
	return 0;
}


第五十五个RegDeleteValue根据子键句柄删除其下的一个键值


这里直接举一个例子，删除RegSetValueEx函数创建的键值


#include<windows.h>
int main()
{
	HKEY hroot;//子键句柄
	DWORD dwDisposition;
	RegCreateKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0,
		NULL, 0, KEY_ALL_ACCESS, NULL, &hroot, &dwDisposition);
	RegDeleteValue(hroot, "AutoRun");//删除子键下名为AutoRun的键值
	return 0;
}


第五十六个RegQueryValueEx根据子键句柄获取一个键值数据，类型。


函数定义：LONG
RegQueryValueEx(
	HKEY hKey,//根键句柄
	LPCWSTR lpValueName,//键值名称
	LPDWORD lpReserved,//预留，填0
	LPDWORD lpType,//接收键值类型
	LPBYTE lpData,//接收键值数据
	LPDWORD lpcbData//接收数据的大小
);


例子，获取RegSetValueEx函数创建的键值的类型，数据


#include<windows.h>
#include<stdio.h>
int main()
{
	char Data[52];
	DWORD Size, Type;
	HKEY hroot;//子键句柄
	DWORD dwDisposition;
	RegCreateKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0,
		NULL, 0, KEY_ALL_ACCESS, NULL, &hroot, &dwDisposition);//获取根键句柄
	RegQueryValueEx(hroot, "AutoRun", 0, &Type, (BYTE*)Data, &Size);//获取AutoRun的信息
	printf("键值名称：AutoRun ");
	switch (Type)
	{
	case REG_SZ:printf("键值类型：REG_SZ"); break;
	case REG_BINARY:printf("键值类型:REG_BINARY"); break;
	case REG_DWORD:printf("键值类型:REG_DWORD"); break;
	case REG_MULTI_SZ:printf("键值类型:REG_MULTI_SZ"); break;
	case REG_EXPAND_SZ:printf("键值类型:REG_EXPAND"); break;
	}
	printf(" 键值数据：%s %d\n", Data, Size);
	return 0;
}


第五十七个RegEnumValue根据子键句柄返回对应索引的键值信息（名称，数据，类型，子键下第一个键值索引为0，以此类推，函数成功执行返回ERROR_SUCCESS）


函数定义：LONG
RegEnumValue(
	HKEY hKey,//子键句柄
	DWORD dwIndex,//键值索引
	LPWSTR lpValueName,//接收键值名称，字符数组
	LPDWORD lpcbValueName,//指明数组大小
	LPDWORD lpReserved,//预留，0
	LPDWORD lpType,//键值类型，填NULL，不获取
	LPBYTE lpData,//键值数据，填NULL，不获取
	LPDWORD lpcbData//接收数据的大小，如果键值数据那项参数为NULL，则该项也为NULL
);


例子：输出Run下的所有键值名


#include<windows.h>
#include<stdio.h>
int main()
{
	char Name[52];
	int Index = 0;
	DWORD dwSize = 52;
	DWORD Size, Type;
	HKEY hroot;//子键句柄
	DWORD dwDisposition;
	RegCreateKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0,
		NULL, 0, KEY_ALL_ACCESS, NULL, &hroot, &dwDisposition);//获取根键句柄
	while (RegEnumValue(hroot, Index, Name, &dwSize, NULL, NULL, NULL, NULL) == ERROR_SUCCESS)
	{
		printf("%s\n", Name);
		Index++;//索引从0开始每次自增一，函数如果执行失败，则索引已到头
	}
	return 0;
}


其实也还可以扩充一下，可以像msconfig程序那样列出当前计算机的所有开机自启动程序，当然，注册表也不只就前面的那一个子键下可以添加自启动程序，在HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run下也可以添加，所以这些子键都需要去查看，更多添加自启动程序的子键可以到百度里去搜一下，大家如果掌握前面那几个注册表操作函数，可以结合起来试着做一个可以添加，查看，删除开机自启动程序的小程序。


第五十八个ExitWindowsEx关机，重启，注销计算机函数


这个函数只有两个参数，后一个参数为系统预留，填0就可以了，而第一个参数则，指明关机，还是重启，或注销，可选值如下：


EWX_LOGOFF//注销 EWX_REBOOT//重启 NT系统中需SE_SHUTDOWN_NAME 特权 EWX_SHUTDOWN//关机，需权限。


例子：关闭计算机，由于需要SE_SHUTDOWN_NAME权限，所以我们得先提升权限，代码如下：


#include<windows.h>
int main()
{
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
	::ExitWindowsEx(EWX_SHUTDOWN, 0);
	return 0;
}


第五十九个VirtualAllocEx在其它的进程中分配内存空间


函数定义：LPVOID
VirtualAllocEx(
	HANDLE hProcess,//进程句柄，将会在该进程句柄相关的进程分配空间
	LPVOID lpAddress,//默认为系统指定，填NUL
	DWORD dwSize,//分配多大的内存
	DWORD flAllocationType,//填MEM_COMMIT
	DWORD flProtect//指定分配的内存属性，为PAGE_READWRITE，内存可读写
);


函数返回分配的内存首地址，


第六十个CreateRemoteThread创建一个远程线程（在其它进程中创建线程）


函数定义：HANDLE
WINAPI
CreateRemoteThread(HANDLE hProcess,//进程句柄，函数将在这个进程句柄关联的进程创建线程


	LPSECURITY_ATTRIBUTES lpThreadAttributes,


	DWORD dwStackSize,
	LPTHREAD_START_ROUTINE lpStartAddress,
	LPVOID lpParameter,
	DWORD dwCreationFlags,
	LPDWORD lpThreadId
);


这个函数比CreateThread函数多了一个参数，就是这个函数的第一个hProcess（函数在该进程里创建线程），后面的六个参数跟第三十九个函数CreateThread的六个参数一样，这里就不再解释了。


例子：远程线程注入


创建一个远程线程，就必须得有一个线程函数供线程执行，而线程函数又不能在其它程序里。那要怎么办呢？大家看一下线程函数的定义，和LoadLibrary函数的定义，它们的定义相似，都是只有一个参数，而且每个程序都能调用LoadLibrary函数，这样我们便能把LoadLibrary函数作为线程函数。这样创建的线程就会去执行LoadLibrary函数。因而我们就有了一次让其它程序调用LoadLibrar函数的机会，并还可以指定LoadLibrary函数的参数（通过创建远程线程函数传递）。前面在动态链接库提到，一个程序如果调用LoadLibrary函数，它都会自动去执行相应动态链接库里的DllMain函数，所以我们自己可以编写一个动态链接库，在DllMain函数里写入想要其它程序执行的代码。再通过CreateRemoteThread函数在其它程序创建一个线程去执行LoadLibary加载我们已经编写好的动态链接库，这样就可以让其它程序执行我们的代码了。这里还有一个问题，CreateRemoteThread函数传递过去的参数，因为要供注入的那个程序访问，所以参数数据所存储的空间不能在调用CreateRemoteThread函数的程序里。必须调用VirtualAllocEx函数，在注入程序里分配一个空间，把数据（动态链接库的名称）存在里面，而新分配空间的首地址则作为CreateRemoteThread函数的参数传过去。这样注入程序访问的是自己的地址空间。


远程线程注入：


假设动态链接库为“ReCode.dll”它的代码如下：


#include<windows.h>
BOOL APIENTRY DllMain(HANDLE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved
)//DllMain函数，只要加载这个动态链接库的程序，都会跑来执行这个函数
{//在这里填让其它程序执行的代码
	while (1)
	{
		MessageBox(NULL, "aaaa", "aaaa", MB_OK);//简单的让其它程序每隔3秒弹出一个提示框
		Sleep(3000);
	}
	return TRUE;
}


编译运行，然后把生成的“ReCode.dll”文件复制到c:\\windows\\system23下去。


注入线程的代码：


//选择ctfmon.exe（输入法管理）作为我们要注入进线程的程序
#include<windows.h>
#include<tlhelp32.h>
#include<stdio.h>
int main()
{
	char DllName[25] = "ReCode.dll";
	HANDLE hProcess;//用于存储ctfmon.exe的进程句柄
	//先提升进程权限，使其能获取任何进程句柄，并对其进行操作
	HANDLE hToken;
	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);
	TOKEN_PRIVILEGES tp;
	LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
	tp.PrivilegeCount = 1;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), NULL, NULL);
	////////////////////////////////////////////////////////////////////////////
	//Process32First和Process32Next函数结合（寻找）获取ctfmon.exe进程ID号
	//再调用OpenProcess函数根据进程ID获得进程句柄
	PROCESSENTRY32 pe32;//进程相关信息存储这个结构里
	pe32.dwSize = sizeof(pe32);
	//给系统内的所有进程拍一个快照
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
	while (bMore)
	{
		if (strcmp("ctfmon.exe", pe32.szExeFile) == 0)//如果找到进程名为ctfmon.exe
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);//获取句柄
		bMore = ::Process32Next(hProcessSnap, &pe32);//寻找下一个
	}


	//在ctfmon进程中分配空间
	LPVOID lpBuf = VirtualAllocEx(hProcess, NULL, strlen(DllName), MEM_COMMIT, PAGE_READWRITE);
	DWORD WrSize;
	//把DllName里的数据写入到分配的空间里
	WriteProcessMemory(hProcess, lpBuf, (LPVOID)DllName, strlen(DllName), &WrSize);
	//创建远程线程
	CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, lpBuf, 0, NULL);
	return 0;//程序使命完成，结束
}


当然, 给一个程序安装钩子, 也可以让指定的应用程序加载特定的动态链接库, 但要了解, 加载动态链接库的是是应用程序的主程序, 你总不能让应用程序不干它自己的事, 而来一直执行DllMain函数里的代码吧!而且即使这样, 当安装钩子的程序退出或卸载钩子的时候，那么被系统强迫加载动态链接库的程序，也会自动释放动态链库，退出DllMain函数。如此，那就没有办法了吗？，办法肯定是有的，用CreateThread函数。当其它程序主线程执行DllMain函数的时候，使其调用CreateThread再创建一个线程，就行了。





http://hi.baidu.com/3582077/item/8d80115206f504968c12ed19


第六十一个GetWindowThreadProcessId根据窗口句柄获得对应进程ID号, 和线程ID号


函数只有两个参数，第一个参数是窗口句柄，第二个参数是一个DOWRD类型的指针(进程ID）, 函数返回线程ID


	如 :


DWORD ThreadId, ProcessId;


ThreadId = GetWindowThreadProcessId(wnd, &ProcessId);


第六十二个EnumWindows枚举当前正运行的所有主窗口，不包括子窗口


调用这个函数，还必须定义一个回调函数，它的格式是这样的：BOOL CALLBACK lpEnumFunc(HWNDwnd, LPARAM lParam);


EnumWindows函数有两个参数，第一个就是回调函数的地址，另一个是自定义参数，对应着回调函数的第二个参数。


每枚举一次窗口，这个回调函数就会被执行一次，而获得的窗口句柄，就会传递给回调函数，对应着回调函数的第一个参数。直到枚举完所有窗口。而在回调用函数里，返回真表示继续枚举，返回假则停止枚举。


例子：枚举窗口


#include<windows.h>
#include<stdio.h>
BOOL CALLBACK lpEnumFunc(HWND hwnd, LPARAM lParam);
int main()
{
	::EnumWindows(lpEnumFunc, 0);
	return 0;
}
BOOL CALLBACK lpEnumFunc(HWND wnd, LPARAM lParam)
{
	char WindowName[52] = { 0 };
	GetWindowText(wnd, WindowName, sizeof(WindowName));//根据窗口句柄获得窗口名
	printf("窗口句柄:%d 窗口名称:%s\n,", wnd, WindowName);


	//可以在这里加个判断当前是否有一个窗口正在运行


	//如if(strcmp(WindowName,"Windows任务管理器")==0) return 0;结束枚举，
	return 1;
}


第六十三个MessageBox弹出一个消息提示框


int
MessageBox(
	HWND hWnd,//指明消息框是属于哪个窗口的，可以为NULL
	LPCSTR lpText,//消息提示具体内容
	LPCSTR lpCaption,//提示框窗口标题
	UINT uType);//指明提示框类型，按钮，图标
这里只说下uType的常用可选值：
按钮：
MB_ABORTRETRYIGNORE 终止 重试 忽略
MB_OK 确定
MB_OKCANCEL 确定 取消
MB_RETRYCANCEL 重试 取消
MB_YESNO 是 否
MB_YESNOCANCEL 是 否 取消
图标：
MB_ICONWARNING 感叹号
MB_ICONINFORMATION 提示i
MB_ICONQUESTION 问号
MB_ICONSTOP 红X号
按钮和图标可以结合用，如：
MessageBox(NULL, "该内存不能访问", "出错", MB_OK | MB_ICONSTOP);


系统模式：MB_SYSTEMMODAL
函数的返回值确定用户选择了哪个按钮，正面给各按钮的定义：
IDABORT “放弃”按钮
IDCANCEL “取消”按钮
IDIGNORE “忽略”按钮
IDNO “否”按钮
IDOK 确定
IDRETRY 重试
IDYES 是
判断返回值是否与其相等即可。


第六十四个GetForegroundWindow获得当前激活的窗口句柄


函数没参数，调用即返回最前窗口句柄


这里举一个例子：每当切换窗口的时候弹出一个消息提示框


#include<windows.h>
int main()
{
	char WindowName[52];
	HWND wnd, Orgwnd;
	wnd = Orgwnd = NULL;
	while (1)
	{
		wnd = GetForegroundWindow();
		if (wnd != Orgwnd)
		{
			GetWindowText(wnd, WindowName, sizeof(WindowName));
			MessageBox(NULL, WindowName, "切换窗口到", MB_OK);
			Orgwnd = wnd;
		}
		Sleep(200);
	}
}


第六十五个GetTopWindow根据窗口句柄获得其下第一子窗口句柄（如果有）


用过MFC的人都知道，在对话编辑区，如果要为控件排序的话，就按CTRL + D显示出每个控件的顺序，如下图：




而GetTopWindow函数获取的就是控件顺序为1的窗口句柄。


例子：改变一个主窗口下的第一子窗口的显示内容（前提得它有），这里就以上面那个abc对话框为例：


#include<windows.h>
int main()
{
	HWND wnd;
	wnd = FindWindow(NULL, "abc");
	HWND FirstWnd = GetTopWindow(wnd);
	SetWindowText(FirstWnd, "first");
	return 0;


}


执行效果：


第六十六个GetNextWindow根据子窗口句柄获得下一个或上一个同级的窗口句柄（返回NULL，函数执行失败）


函数有两个参数，第一个是子窗口句柄，第二个参数指明寻找上一个，还是一下个窗口句柄，值：GW_HWNONEXT（下一个），GW_HWNDPREV（上一个）。比如子窗口句柄在主窗口的顺序为3，那么获取的是顺序为2或顺序为3的窗口句柄（具体取决于第二个参数），函数返回获得的窗口句柄.这样GetNextWindow结合GetTopWindow函数就可以遍历一个主窗口里的所有子窗口了。


例子：遍历一个窗口里的所有子窗口，以上面的abc窗口为例


#include<stdio.h>
#include<windows.h>
int main()
{
	char Name[52];
	HWND wnd;
	wnd = FindWindow(NULL, "abc");
	wnd = GetTopWindow(wnd);
	while (wnd != NULL)
	{
		GetWindowText(wnd, Name, sizeof(Name));
		printf("窗口句柄:%d,名称:%s\n", wnd, Name);
		wnd = GetNextWindow(wnd, GW_HWNDNEXT);//GW_HWNDNEXT获取下一个
	}
	return 0;
}


第六十七个InvalidateRect发送一个WM_PAINT消息给窗口（刷新窗口）


函数定义：BOOL
InvalidateRect(
	HWND hWnd,//要刷新窗口的句柄
	CONST RECT *lpRect,//刷新的范围
	BOOL bErase//重画为TRUE


);


例子：在SetTimer函数里会举例


第六十八个SetTimer设置一个定时器（每隔一段时间执行一次定时器函数）


函数定义：UINT
SetTimer(
	HWND hWnd,//窗口句柄
	UINT nIDEvent,//定时器ID号，为了能设置多个定时器
	UINT uElapse,//时间，指明间隔多久执行一次定时器函数，单位：毫秒
	TIMERPROC lpTimerFunc);//定时器回调函数的地址


定时器函数的固定格式：VOID CALLBACK TimerProc(HWND hwnd, UINTuMsg, UINT_PTR idEvent, DWORD dwTime);


例子：在用w, a, s, d键控制一个矩形移动的同时，一个相同的矩形自动移动。


#include<windows.h>
LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);//函数声明
VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{


	WNDCLASS wndcls; //定义一个存储窗口信息WNDCLASS变量
	wndcls.cbClsExtra = 0; //默认为0
	wndcls.cbWndExtra = 0; //默认为0
	wndcls.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); //背景画刷
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW); //光标
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR); //窗口图标
	wndcls.hInstance = hInstance; //应用程序实例句柄由WinMain函数传进来 
	wndcls.lpfnWndProc = WinSunProc; //窗口消息处理函数
	wndcls.lpszClassName = "windowclass"; //窗口类名
	wndcls.lpszMenuName = NULL; //窗口菜单名，没有菜单，为NULL
	wndcls.style = CS_HREDRAW | CS_VREDRAW;//窗口类型，CS_HREDRAW和CS_VERDRAW 表明
	//当窗口水平方向垂直方向的宽度变化时重绘整个窗口
	RegisterClass(&wndcls); //把窗口信息提交给系统，注册窗口类
	HWND hwnd; //用以存储CreateWindow函数所创建的窗口句柄
	hwnd = CreateWindow("windowclass", "first windows",
		WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);//创建窗口
	ShowWindow(hwnd, SW_SHOWNORMAL);//窗口创建完了，显示它
	UpdateWindow(hwnd); //更新窗口，让窗口毫无延迟的显示
	SetTimer(hwnd, 1, 200, (TIMERPROC)TimerProc);//设置定时器
	MSG msg;//消息结构类型
	while (GetMessage(&msg, NULL, 0, 0))//获取消息
	{
		TranslateMessage(&msg); //此函数用于把键盘消息(WM_KEYDOWN,WM_KEYUP)转换成字符消息WM_CHAR
		DispatchMessage(&msg); //这个函数调用窗口过程处理函数，并把MSG里的信息处理后传给过程函数的四个参数
	}
	return 0;
}
VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)//定时器函数
{
	static int x = 0, y = 0;
	x += 15;
	if (x > 500)
	{
		y += 15; x = 0;
	}
	HDC dc = GetDC(hwnd);
	Rectangle(dc, x, y, x + 30, y + 30);
}
LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static int x = 0, y = 0;
	switch (uMsg)
	{


	case WM_CHAR:
	{
		if (wParam == 'a') x -= 10;
		else if (wParam == 'd') x += 10;
		else if (wParam == 'w') y -= 10;
		else if (wParam == 's') y += 10;
		RECT rect;
		GetClientRect(hwnd, &rect);
		::InvalidateRect(hwnd, &rect, TRUE);//发送WM_PAINT消息，刷新窗口
	}
	break;
	case WM_PAINT:
		HDC dc;
		PAINTSTRUCT ps;
		dc = BeginPaint(hwnd, &ps); //BeginPaint只能在响应WM_PAINT,不能用GetDC获取设备上下文
		Rectangle(dc, x, y, x + 30, y + 30);
		break;
	case WM_CLOSE://用户关闭了窗口
		DestroyWindow(hwnd);//销毁窗口，并发送WM_DESTROY消息
		break;
	case WM_DESTROY://如果窗口被销毁
		PostQuitMessage(0);//让进程退出
		break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam); //未处理的消息通过DefWindowProc函数交给系统处理
}


第六十九个RegisterHotKey注册一个热键


函数定义：BOOL
RegisterHotKey(
	HWND hWnd,
	int id,
	UINT fsModifiers,
	UINT vk);


第一个参数hWnd表明热键消息（HOT_KEY）发送给哪个窗口，为NULL表明直接把消息投递给调用这个函数进程的消息队列。


第二个参数可以自定取值，取值范围0xC000 - 0xFFFF, 这个参数是为了程序能同时拥有多个热键而存在。


第三个参数fsModifiers的可选取值如下：MOD_ALT（Alt键），MOD_CONTROL（Ctrl键），MOD_SHIFT（Shift键），MOD_WIN（‘田’图标键）
最一个参数是一个ASCII值，指明具体和哪个非系统键组合。
如QQ的热键ctrl + alt + z，注册这个热键的语句是RegisterHotKey(NULL, 0x0001, MOD_CONTROL | MOD_ALT, ‘Z’)
如QQ的截图热键RegisterHotKey(NULL, 0x0001, MOD_CONTROL | MOD_ALT, 'A')


例子：按下ctrl + alt + x热键，弹出消息提示框，询问是否要退出。


//#include "stdafx.h" 新建空工程，不需要该头文件
#include<windows.h>
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	RegisterHotKey(NULL, 0x0001, MOD_CONTROL | MOD_ALT, 'X');//注册热键
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))//从消息队伍获取消息
	{
		if (msg.message == WM_HOTKEY)//热键消息
		{
			if (MessageBox(NULL, "你确定要退出程序吗？", "热键提示", MB_YESNO | MB_SYSTEMMODAL) == IDYES)
			{
				UnregisterHotKey(NULL, 0x0001);//卸载热键
				break;
			}
		}
	}
	return 0;
}


记得要退出程序


第七十个StretchBlt在窗口输出一个位图


这个函数比BitBlt多了两个参数，那就是源目标DC的宽高，像BitBlt函数，只有目标DC的宽高。


有了这两个参数的加入，StretchBlt函数功能就比BitBlt函数强大了许多，它可以缩小或放大图片，可以把一张图片上的任意矩形区域覆盖到另一张图片上的任意区域。


函数语句：StretchBlt(hdc, 0, 0, bmInfo.bmWidth, bmInfo.bmHeight, memDC, 0, 0, 50, 50, SRCCOPY);


具体用法参考BitBlt函数。


例子：在窗口输出不规则形状的位图。


说明：


位图其实都是矩形，这里要说的是可以输出位图里的任意形状部分，但位图不输出的部分，必须是固定的颜色


为什么呢？白色的RGB值是255，255，255，把255转换成二进制，可以看到每一位都是1，如：11111111.这样任何一种颜色与白色进行按位与运算，其结果都不会变，这样两个DC合并进行按位与（SRCAND）运算，白色的部分都会被屏蔽，而任何一种颜色与黑色进行按位与运算，其结果都为黑色，与黑色进行按位或（SRCAND）运算，其结果不会改变。黑色的RGB值是0，0，0。


输出这样的图形，要准备两张图片，必须是这种模式，如下：


flower1 flower2


这里要输出在窗口里的是flower2图片里的花，黑色部分不输出


假设这两张图片在E盘，看例子：


#include<windows.h>
int main()
{
	HWND wnd = FindWindow(NULL, "无标题.txt - 记事本");


	HBITMAPhBmp1 = (HBITMAP)LoadImage(NULL, "e:\\flower1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	HBITMAPhBmp2 = (HBITMAP)LoadImage(NULL, "e:\\flower2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BITMAP bmInfo;
	GetObject(hBmp1, sizeof(BITMAP), &bmInfo);
	HDC dc = GetDC(wnd);
	HDC memDC;
	memDC = CreateCompatibleDC(dc);
	while (1)
	{
		SelectObject(memDC, hBmp1);
		StretchBlt(dc, 0, 0, bmInfo.bmWidth, bmInfo.bmHeight, memDC,
			0, 0, bmInfo.bmWidth, bmInfo.bmHeight, SRCAND);//按位与运算合并DC
		SelectObject(memDC, hBmp2);
		StretchBlt(dc, 0, 0, bmInfo.bmWidth, bmInfo.bmHeight, memDC,
			0, 0, bmInfo.bmWidth, bmInfo.bmHeight, SRCPAINT);//按位或运算合并DC
		Sleep(200);
	}


}


运行效果如下图：








http://hi.baidu.com/3582077/item/5668f7ef963711d3ea34c919


第七十一个TextOut根据设备DC在窗口输出文字


函数定义 : BOOL TextOut(HDC hdc,// 设备DC
	int nXStart,// 窗口x坐标
	int nYStart,// 窗口y坐标，字符串左上角是将是x,y
	LPCTSTR lpString,// 字符串
	int cbString// 字符串中字符的个数
);


例子：在窗口输出文字，为了方便，这里依旧在"无标题.txt - 记事本", 窗口里输出文字


#include<windows.h>
#include<string.h>
int main()
{
	char Text[52] = "从坐标点50,50开始输出文字";
	HWND wnd = FindWindow(NULL, "无标题.txt - 记事本");
	HDC dc = GetDC(wnd);
	SetTextColor(dc, RGB(255, 0, 0));//设置文字颜色
	while (1)
	{
		TextOut(dc, 50, 50, Text, strlen(Text));
		Sleep(200);
	}
	return 0;
}


第七十二个DrawText根据设备DC在窗口的一个矩形区输出文字。
int
DrawTextW(
	HDC hDC,//设备DC
	LPCWSTR lpString,//字符串
	int nCount,//字符串的个数
	LPRECT lpRect,//指明一个矩形区
	UINT uFormat);//输出格式


uFormat的常用取值


值 说明
DT_BOTTOM 将正文调整到矩形底部。此值必须和DT_SINGLELINE组合。
DT_CENTER 使正文在矩形中水平居中。
DT_VCENTER 使正文在矩形中垂直居中。
DT_END_ELLIPSIS 对于显示的文本，如果结束的字符串的范围不在矩形内，它会被截断并以省略号标识。
如果一个字母不是在字符串的末尾处超出了矩形范围，它不会被截断并以省略号标识。
字符串不会被修改，除非指定了DT_MODIFYSTRING标志。
T_WORD_ELLIPSIS, DT_PATH_ELLIPSIS和DT_END_ELLIPSIS不能和此参数一起使用
DT_LEFT 正文左对齐。
T_RIGHT 正文右对齐。
DT_RTLREADING 当选择进设备环境的字体是希伯来文或阿拉伯文字体时，为双向正文安排从右到左的阅读顺序都是从左到右的。
DT_TOP 正文顶端对齐（仅对单行）。
DT_WORDBREAK 断开字。当一行中的字符将会延伸到由lpRect指定的矩形的边框时，此行自动地在字之间断开。一个回车一换行也能使行折断。
DT_WORD_ELLIPSIS 截短不符合矩形的正文，并增加省略号。


第七十三个GetLogicalDriveStrings获取系统分区信息


函数定义：DWORD
GetLogicalDriveStrings(
	DWORD nBufferLength,//指明lpBuffer参数大小
	LPSTR lpBuffer//分区信息将会存储在这个参数，格式是“分区NULL分区NULL分区NULLNULL”两个NULL结尾


	//假设当前电脑有C，D，E分区，那字符串的存储格式是"C:\\\0D:\\\0E:\\\0\0"; ('\\'转义字符\)
);


例子：枚举当前磁盘所有分区


#include<windows.h>
#include<stdio.h>
int main()
{
	char *szBuffer = new char[52];
	GetLogicalDriveStrings(52, szBuffer);
	while (*szBuffer != '\0')
	{
		printf("%s\n", szBuffer);
		szBuffer += strlen(szBuffer) + 1;
	}
	return 0;
}


第七十四个GetDiskFreeSpaceEx获取一个分区（盘符）的信息（已用空间，总大小，可用空间）


这个函数必须用ULARGE_INTEGER联合类型来存储磁盘使用信息。因为要获取磁盘的已用空间，总大小，可用空间，所以我们必须定义三个ULARGE_INTEGER类型变量来存储这三个信息。而具体信息就存储在ULARGE_INTEGER类型的QuadPart成员变量（该成员占八位字节）


如获取C盘的信息：ULARGE_INTEGERdwAvailable, dwFree, dwTotal;


GetDiskFreeSpaceEx("c:\\", &dwAvailable, &dwTotal, &dwFree);//获取分区信息


下面结合GetLogicalDriveStrings举个例子：获取当前磁盘所有分区信息并输出


#include<windows.h>
#include<stdio.h>
int GetSpace(char *P);
int main()
{
	char *szBuffer = new char[52];
	GetLogicalDriveStrings(52, szBuffer);
	while (*szBuffer != '\0')
	{
		printf("%s ", szBuffer);
		GetSpace(szBuffer);
		szBuffer += strlen(szBuffer) + 1;
	}
	return 0;
}
int GetSpace(char *Par)
{
	ULARGE_INTEGER dwAvailable, dwFree, dwTotal;
	double fDwa, fDwf, fDwt;
	char szSize[128] = { 0 };
	int Size;
	GetDiskFreeSpaceEx(Par, &dwAvailable, &dwTotal, &dwFree);//获取分区信息
	Size = dwTotal.QuadPart / 1024 / 1024;//获取总大小
	fDwt = Size / 1024.0;
	Size = dwAvailable.QuadPart / 1024 / 1024;//获取已用空间
	fDwa = Size / 1024.0;
	Size = dwFree.QuadPart / 1024 / 1024;//获取可用空间
	fDwf = Size / 1024.0;
	sprintf(szSize, "总大小:%0.2fGB 已用空间:%0.2fGB 可用空间:%0.2fGB", fDwt, fDwa, fDwf);
	printf("%s\n", szSize);
	return 0;
}


第七十五个WritePrivateProfileString修改或创建一个INI文件里的数据


INI文件的内容一般由节名，键名，键值组成，先来看一下INI文件的结构，打开一个INI文件, 我们可能会看到以下内容


////////////////////////////////////////////////////////////////////////////////////


[gmy_p]
exist_p = 0
linux_p =


[boot]
a20 = 0
a21 = 0


///////////////////////////////////////////////////////////////////////////////////


上面的内容中[gmy_p]和[boot]便是INI文件的节名，节名包含键名，和键值。一个INI文件可以有多个节名.


那么哪些是键名，那些是键值呢，在“ = ”左边的是键名，而在右边的就是键值，键值可以为NULL。


好了，看一下WritePrivateProfileString的函数的定义：


BOOL
WritePrivateProfileString(
	LPCWSTR lpAppName,//节名
	LPCWSTR lpKeyName,//键名
	LPCWSTR lpString,//修改的数据
	LPCWSTR lpFileName//INI文件名
);


如果要修改键值，那么要提供哪些信息呢，首先，必须要知道INI文件的路径（lpFileName)，要修改的键值是在哪个节名下(lpAppName)，以及具体是哪个键名(lpKeyName)，还有修改的键值数据(lpString).


比如我要把之前INI文件里节名为gmy_p下的键名exist_p的键值改为100(假设这个文件的路径为d:\gho.ini).


那么就是语句：WritePrivateProfileString("gmy_p", "exist_p", "100", "d:\\gho.ini");


WritePrivateProfileString函数功能不止于此，当函数提供的INI文件名，节名，键名不存在时，那么函数就会创建他们。这样，我们就可以用这个函数创建一个INI文件，或在一个INI文件里创建一个节名，或在一个节名下创建一个键名。


如：WritePrivateProfileString("ZhengYong", "QQ", "***980073", "d:\\Info.ini");


第七十六个GetPrivateProfileString获取一个INI文件里的数据


函数定义：DWORD
GetPrivateProfileStringW(
	LPCWSTR lpAppName,//节名
	LPCWSTR lpKeyName,//键名
	LPCWSTR lpDefault,//默认值，填0既可
	LPWSTR lpReturnedString,//接收数据的缓存区（字符串）
	DWORD nSize,//指明缓存区的大小
	LPCWSTR lpFileName//INI文件名
);


例子获取一个键值：假设D盘下有一个名为Info.ini文件，它的内容如下：


////////////////////////////////////////////////////////////////////////////


[ZhengYong]
QQ = ***980073
Age = 100
Weight = 65kg
[LiYang]
QQ = ***990129
Age = 22
Weight = 55kg


///////////////////////////////////////////////////////////////////////////


如果我想要获取节名为"ZhengYong"下的键名QQ的键值，那么就是：


#include<windows.h>
#include<stdio.h>
int main()
{
	char KeyValue[252];
	::GetPrivateProfileString("ZhengYong", "QQ", 0, KeyValue, 252, "d:\\Info.ini");
	printf("%s\n", KeyValue);
	return 0;
}


同WritePrivateProfileString类似，如果提供的节名，或键名为NULL，则获取当前所有的节名或键名。跟分区信息存储格式一样，字符串里，多个节名，或键名以'\0'间隔，字符串最终以两个'\0'结束。


例子：枚举ZhengYong节名下的所有键名：


#include<windows.h>
#include<stdio.h>
int main()
{
	char Data[252];
	::GetPrivateProfileString("ZhengYong", NULL, 0, Data, 252, "d:\\Info.ini");
	char *pKey = Data;
	while (*pKey != '\0')
	{
		printf("%s\n", pKey);
		pKey += strlen(pKey) + 1;
	}
	return 0;
}


那么枚举节名只要在上面的例子中，把函数的节名参数设为NULL就行了，如：


GetPrivateProfileString(NULL, NULL, 0, Data, 252, "d:\\Info.ini");


大家可以用这个函数编一个读取INI文件内容的程序，以便更好的掌握这个函数。记得把接收数据的缓存区设置大一点。


第七十七个GetSystemMetrics获得特定窗口的高宽度


该函数只有一个参数，常用取值如下：


SM_CXSCREEN 屏幕宽度


SM_CYSCREEN屏幕高度


SM_CXFULLSCREEN窗口客户区宽度


SM_CYFULLSCREEN窗口客户区高度


SM_CYMENU菜单栏高度


SM_CYCAPTION//标题栏高度


SM_CXBORDER窗口边框宽度


SM_CYBORDER窗口边框高度


SM_CXSIZE 标题栏上的按钮宽度
SM_CYSIZE 标题栏上的按钮高度


例子：获取屏幕分辨率（桌面宽高度）


#include<windows.h>
#include<stdio.h>
int main()
{
	int ScreenX = ::GetSystemMetrics(SM_CXSCREEN);
	int ScreenY = ::GetSystemMetrics(SM_CYSCREEN);
	printf("屏幕分辨率:%dX%d\n", ScreenX, ScreenY);
	return 0;
}


第七十八个SetWindowPos设置一个窗口的大小和它的Z序


窗口的Z序是什么意思呢？用过MFC的人应该都清楚，在对话框编辑区按CTRL + D就会显示出每个控件的顺序。如下图：


设置控件的顺序有什么用呢，大家看到上面两个控件有什么特别的吗？对了，两个控件正好有一部分重叠，这时候问题就来了，重叠的部分显示的是那个窗口呢，或者说是以什么来确定显示哪个窗口，我想大家也应该猜到了，是以控件的顺序来确定的。顺序较大的会被显示。这个程序运行如下图如示：


明白窗口的Z序了，我们就来看一下这个函数的参数及其意思。


函数定义：BOOL
SetWindowPos(
	HWND hWnd,//要设置的窗口句柄
	HWND hWndInsertAfter,
	int X,
	int Y,//X,Y指明窗口左上角的位置
	int cx,//窗口宽度
	int cy,//窗口高度
	UINT uFlags);


第二个参数hWndInsertAfter的常用取值：


HWND_BOTTOM：
将窗口置于Z序的底部.
HWND_NOTOPMOST：如果窗口在Z序顶部，则取消顶部位置，如果不是，则该参数无效
HWND_TOP : 将窗口置于Z序的顶部。
	HWND_TOPMOST : 将窗口置于Z序的顶部。窗口当前未被激活，也依然是顶部位置


	最后一个参数uFlags可以是Z序中hWnd的前一个窗口句柄的或以下常用取值：


	SWP_HIDEWINDOW; 隐藏窗口


	SWP_SHOWWINDOW：显示窗口


	SWP_NOMOVE指明X, Y参数无效


	SWP_NOSIZE指明CX, CY参数无效


	SWP_NOZORDER指明hWndInsertAfter参数无效


	例子：设置一个窗口像PPS和任务栏那样，总在最前显示。


	以"无标题.txt - 记事本"窗口为例


#include<windows.h>
	int main()
{
	HWND wnd = ::FindWindow(NULL, "无标题.txt - 记事本");
	::SetWindowPos(wnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE);
	return 0;
}


例子2：全屏一个窗口


依旧以"无标题.txt - 记事本"窗口为例：


#include<windows.h>
int main()
{
	int ScreenX = ::GetSystemMetrics(SM_CXSCREEN);
	int ScreenY = ::GetSystemMetrics(SM_CYSCREEN);
	HWND wnd = ::FindWindow(NULL, "无标题.txt - 记事本");
	::SetWindowPos(wnd, HWND_TOPMOST, 0, 0, ScreenX, ScreenY, SWP_SHOWWINDOW);
	return 0;
}


第七十九个CreateFile创建一个文件，或打开一个文件用于读写, 函数返回文件句柄


函数定义：HANDLE
CreateFile(
	LPCSTR lpFileName,//文件名
	DWORD dwDesiredAccess,//指明对文件进行何种操作，是要读它（GENERIC_READ）还是要写入（GENERIC_WRITE）
	DWORD dwShareMode,//指明文件可以同时被多个程序读写吗？FILE_SHARE_READ可以同时读，FILE_SHARE_WRITED可以同时写
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,//指向一个SECURITY_ATTRIBUTES结构的指针，一般为NULL


	DWORD dwCreationDisposition,//安全属性，指明以何种方式打开或创建文件
	DWORD dwFlagsAndAttributes,//指明文件的属性，隐藏？只读？系统文件？为NULL表示默认属性
	HANDLE hTemplateFile// 如果不为零，则指定一个文件句柄。新文件将从这个文件中复制扩展属性
);


第五个参数dwCreationDisposition的常用取值及意思


TRUNCATE_EXISTING 将现有文件缩短为零长度，清空文件的内容，文件必须已经存在


CREATE_ALWAYS 创建一个文件，如果文件已经存在，则覆盖它


CREATE_NEW 创建文件，如果文件已经存在，则函数执行失败


OPEN_ALWAYS打开文件，如果文件不存在，则创建它


OPEN_EXISTING 打开文件，文件必须存在。


第六个参数dwFlagsAndAttributes的常用取值及其意思


FILE_ATTRIBUTE_NORMAL 默认属性


FILE_ATTRIBUTE_HIDDEN 隐藏


FILE_ATTRIBUTE_READONLY 只读


FILE_ATTRIBUTE_SYSTEM 系统文件


第八十个ReadFile根据文件句柄，从文件中读取一段数据


函数定义：BOOL
WINAPI
ReadFile(
	HANDLE hFile,//文件句柄
	LPVOID lpBuffer,//接收文件数据的缓存区
	DWORD nNumberOfBytesToRead,//指明读取多少数据(字节）
	LPDWORD lpNumberOfBytesRead,//实际读取数据
	LPOVERLAPPED lpOverlapped// 一般为NULL，如文件打开时指定了FILE_FLAG_OVERLAPPED，该参才有具体取值。
);


例子：读取txt文件的内容，假设E盘下有一个名a.txt的文件，文件内容为123456789


#include<windows.h>


#include<stdio.h>


int main()
{
	char Text[25] = { 0 };
	DWORD dwSize;
	HANDLEFileHandle = CreateFile("e:\\a.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING
		, FILE_ATTRIBUTE_NORMAL, NULL);//获取文件句柄
	ReadFile(FileHandle, Text, 15, &dwSize, NULL);//从文件中读取15个字节
	printf("内容：%s 实际读入字节：%d\n", Text, dwSize);
	return 0;
}





http://hi.baidu.com/3582077/item/5f4f58e718028fabc10d751b


第八十一个WriteFile根据文件句柄，写入一段数据到文件中


函数定义：BOOL
WriteFile(
	HANDLE hFile,//文件句柄
	LPCVOID lpBuffer,//该缓存区的数据将要写入到文件里
	DWORD nNumberOfBytesToWrite,//指明写入多少数据
	LPDWORD lpNumberOfBytesWritten,//实际写入数据
	LPOVERLAPPED lpOverlapped//一般为NULL
);
例子：在E盘创建一个名为aa.txt的文件，并向其写入数据


#include<windows.h>


#include<stdio.h>


int main()
{
	char Text[25] = "123456789";
	DWORD dwSize;
	HANDLEFileHandle = CreateFile("e:\\aa.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);
	::WriteFile(FileHandle, Text, 9, &dwSize, 0);
	return 0;
}


第八十二个SetFilePointer移动一个文件指针的位置


移动一个文件指针的位置有什么用呢，作用是读取一个文件里指定位置的数据，比如我只要读取文件中第四个字节到第七个字节这一段的数据，用SetFilePointer函数就可以完成。


函数定义：DWORD
SetFilePointer(
	HANDLE hFile,//文件句柄
	LONG lDistanceToMove,//移动字节，负数表示反向移动
	PLONG lpDistanceToMoveHigh,//为了支持超大文件而存在，一般为NULL
	DWORD dwMoveMethod//从哪里开始移动，FILE_BEGIN 从文件开始处开始移动，FILE_CURRENT当前位置，FILE_END文件末尾
);


例子：假设E盘下有一个名为a.txt的文件，内容为"123456789", 读取该文件第四个字节到第七个字节的数据


#include<windows.h>


#include<stdio.h>


int main()
{
	char Text[25] = { 0 };
	DWORD dwSize;
	HANDLEFileHandle = CreateFile("e:\\a.txt", GENERIC_READ, 0, NULL, OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);
	SetFilePointer(FileHandle, 3, NULL, FILE_BEGIN);
	ReadFile(FileHandle, Text, 4, &dwSize, NULL);
	printf("%s\n", Text);
	return 0;
}


例子2：从文件中第四个字节开始写入数据，被新数据所占位置的数据会被覆盖掉，依旧以上面a.txt文件为例子


#include<windows.h>


#include<stdio.h>


int main()
{
	char Text[25] = { "abcd" };
	DWORD dwSize;
	HANDLE FileHandle = CreateFile("e:\\a.txt", GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);
	SetFilePointer(FileHandle, 3, NULL, FILE_BEGIN);
	WriteFile(FileHandle, Text, 4, &dwSize, NULL);


	return 0;
}


则写入后a.txt文件里的数据为123abcd89


如果要在文件的末尾添加数据，就用这个语句：SetFilePointer(FileHandle, 0, NULL, FILE_END);


第八十三个GetFileSize获取一个文件的大小


函数定义：DWORD
GetFileSize(
	HANDLE hFile,//文件句柄
	LPDWORD lpFileSizeHigh//一般为NULL
);


如获取a.txt文件的大小：


#include<windows.h>


#include<stdio.h>


int main()
{
	DWORD FileSize;
	HANDLE FileHandle = CreateFile("e:\\a.txt", GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);
	FileSize = GetFileSize(FileHandle, NULL);
	printf("%d字节\n", FileSize);
	return 0;
}


第八十四个SetTextColor设置窗口输出文本颜色


第一个参数是设备DC，第二个参数是一个COLORREF类型的颜色值，可用RGB进行转换。


第八十五个SetBkColor设置背景颜色


参数跟SetTextColor函数一样，第一个DC，第二个COLORREF


第八十六个GetWindowDC获取整个窗口设备上下文DC


像GetDC获取的只是客户区DC，不能对窗口标题栏，状态栏等进行操作。该函数用法跟GetDC一样，仅区域不一样。


例子：在一个窗口的标题栏输出文字


#include<windows.h>


int main()


{


	HWND wnd = FindWindow(NULL, "无标题.txt- 记事本");
	HDC dc = GetWindowDC(wnd);
	SetTextColor(dc, RGB(255, 0, 0));//文本颜色设置为红色
	::SetBkColor(dc, RGB(0, 0, 255));//文本背景颜色设置为蓝色
	while (1)
	{
		TextOut(dc, 0, 0, "123456", 6);
		Sleep(200);
	}
	return 0;
}


第八十七个GetDesktopWindow获取桌面窗口句柄


该函数没有参数，调用返回桌面窗口句柄


例子：


#include<windows.h>
int main()
{
	HWND DeskWnd = GetDesktopWindow();//获取桌面窗口句柄
	HDC DeskDC = GetWindowDC(DeskWnd);//获取DC
	HBRUSH brush = ::CreateSolidBrush(RGB(255, 0, 0));//红色画刷
	SelectObject(DeskDC, brush);//选入画刷
	while (1)
	{
		::Rectangle(DeskDC, 50, 50, 200, 200);
		Sleep(200);
	}
	return 0;
}


第八十八个CreateCompatibleBitmap根据DC创造一个兼容的位图


该函数需与CreateCompatibleDC函数配合使用


函数第一个参数是窗口DC，第二，三参数指明窗口宽高，函数返回位图句柄(HBITMAP）


	创建一个兼容的位图是什么意思呢？就好比给HBITMAP分配内存以及指定这位图相关的一些信息（跟DC相关的信息），如位图的宽高，数据大小，但此时数据没有具体取值。就好比一个字符串，我已经知道字符串大小了，但却不知道字符串具体是什么：


	如：


	char *p;


p = new char[15];//知道字符串大小为15


但此时p所指向的缓存区，没有具体取值。


而用CreateCompatibleBitmap函数，创建的位图，只是一个空壳子。数据没有赋值，那要怎样给数据赋值呢？


首先得把这个位图句柄选入一个DC（该DC必须为CreateCompatibleDC函数创建的）里，然后再用BitBlt函数具体给数据赋值就行了。


例子：实时获取屏幕图像


为了方便，在记事本窗口输出图像，自己就不创建窗口了（打开"无标题.txt - 记事本")


#include<windows.h>
int main()
{
	HWND TextWnd = FindWindow(NULL, "无标题.txt - 记事本");
	HDC TextDC = GetDC(TextWnd);
	HWND DeskWnd = ::GetDesktopWindow();
	RECT DeskRC;
	::GetClientRect(DeskWnd, &DeskRC);
	HDC DeskDC = GetDC(DeskWnd);
	HBITMAP DeskBmp = ::CreateCompatibleBitmap(DeskDC, DeskRC.right, DeskRC.bottom);
	HDC memDC;
	memDC = ::CreateCompatibleDC(DeskDC);
	SelectObject(memDC, DeskBmp);
	while (1)
	{
		StretchBlt(memDC, 0, 0, DeskRC.right, DeskRC.bottom, DeskDC, 0, 0, DeskRC.right, DeskRC.bottom, SRCCOPY);
		RECT TextRC;
		GetClientRect(TextWnd, &TextRC);
		::StretchBlt(TextDC, 0, 0, TextRC.right, TextRC.bottom, memDC, 0, 0, DeskRC.right,
			DeskRC.bottom, SRCCOPY);
		Sleep(300);
	}
	return 0;
}


第八十九个GetDIBits从一个兼容位图里获取位图数据
先来分析一下位图文件信息结构，一个位图由以下四部分组成：


位图文件头（BITMAPFILEHEADER）//占14字节


位图信息头（BITMAPINFOHEADER）//占40字节


调色板（LOGPALLETE）//如果是真彩位图，那该部分没有，直接是位图数据


实际位图数据


而GetDIBits函数获取的就是实际位图数据这一部分了。


接来看一下BITMAPFILEHEADER这个结构以及它成员的意思和取值


typedef struct tagBITMAPFILEHEADER {
	WORD bfType;//表示文件类型，值必须为0x4d42
	DWORD bfSize;//文件的大小
	WORD bfReserved1;//保留，必须为0
	WORD bfReserved2;//保留，必须为0
	DWORD bfOffBits;//位图前三部分所占的字节，真彩色位图为54
} BITMAPFILEHEADER;


上面的成员，只有bfSize的取值不确定，其它都一样，也就是说，每个真彩位图，这几个成员取值都是一样的.下面的例子可以说明。


读取一个真彩位图的文件信息头。


#include<windows.h>


#include<stdio.h>
int main()
{
	BITMAPFILEHEADER bfh;
	HANDLEhFile = CreateFile("e:\\aa.bmp", GENERIC_READ, 0, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);
	DWORD dwSize;
	ReadFile(hFile, (void *)&bfh, sizeof(BITMAPFILEHEADER), &dwSize, 0);
	printf("bfType:%x\n", bfh.bfType);
	printf("bfSize:%d\n", bfh.bfSize);
	printf("bfReserved1:%d\n", bfh.bfReserved1);
	printf("bfReserved2:%d\n", bfh.bfReserved2);
	printf("bfOffbits:%d\n", bfh.bfOffBits);
	return 0;
}


再来看一下BITMAPINFOHEADER这个结构以及它成员的意思和取值


typedef struct tagBITMAPINFOHEADER {
	DWORD biSize;//本结构大小，为40
	LONG biWidth;//位图的宽度，以像素为单位
	LONG biHeight;//位图的高度，以像素为单位
	WORD biPlanes;//目标设备的级别，必须是1
	WORD biBitCount;//每个像素所占的位数，24表示真彩位图
	DWORD biCompression;//位图压缩类型，一般为BI_RGB（未经压缩）
	DWORD biSizeImage;//实际位图数据所占用的字节数
	LONG biXPelsPerMeter;//指定目标设备水平分辨率，单位像素/米，为0
	LONG biYPelsPerMeter;//指定目标垂直分辨率真，单位像素/米，为0
	DWORD biClrUsed;//指定目标设备实际用到的颜色数，如果该值为0，则用到的颜色数为2的biBitCount方
	DWORD biClrImportant;//表示图像中重要的颜色数，如果为0，则所有颜色都是重要的。
} BITMAPINFOHEADER;


调色板（LOGPALLETE）由于大部分都是针对真彩位图操作，此部分略过


GetDIBits函数定义：int GetDIBits(


	HDC hdc, //位图兼容的DC


	HBITMAP hbmp, //位图句柄


	UINT uStartScan, //从哪行开始扫描


	UINT cScanLines, //扫描多少行数据


	LPVOID lpvBits, //接收数据的缓存区


	LPBITMAPINFO lpbi, //真彩位图，此处填位图信息头就行了


	UINT uUsage//真彩位图填DIB_RGB_COLORS，表示由R,G,B三色直接构成


);


例子：截屏，并把屏幕图片保存成位图


#include<windows.h>
void ScreenSnap(HBITMAP hBitmap, char *bmpPath, HDC dc);
int main()
{
	HWND DeskWnd = ::GetDesktopWindow();//获取桌面窗口句柄
	RECT DeskRC;
	::GetClientRect(DeskWnd, &DeskRC);//获取窗口大小
	HDC DeskDC = GetDC(DeskWnd);//获取窗口DC
	HBITMAP DeskBmp = ::CreateCompatibleBitmap(DeskDC, DeskRC.right, DeskRC.bottom);//兼容位图
	HDC memDC = ::CreateCompatibleDC(DeskDC);//兼容DC
	SelectObject(memDC, DeskBmp);//把兼容位图选入兼容DC中
	BitBlt(memDC, 0, 0, DeskRC.right, DeskRC.bottom, DeskDC, 0, 0, SRCCOPY);//拷贝DC
	ScreenSnap(DeskBmp, "d:\\Screen.bmp", DeskDC);
	return 0;
}
void ScreenSnap(HBITMAP hBitmap, char *bmpPath, HDC dc)
{
	BITMAP bmInfo;
	DWORD bmDataSize;
	char *bmData;//位图数据
	GetObject(hBitmap, sizeof(BITMAP), &bmInfo);//根据位图句柄，获取位图信息
	bmDataSize = bmInfo.bmWidthBytes*bmInfo.bmHeight;//计算位图数据大小
	bmData = new char[bmDataSize];//分配数据
	BITMAPFILEHEADER bfh;//位图文件头
	bfh.bfType = 0x4d42;
	bfh.bfSize = bmDataSize + 54;
	bfh.bfReserved1 = 0;
	bfh.bfReserved2 = 0;
	bfh.bfOffBits = 54;
	BITMAPINFOHEADER bih;//位图信息头
	bih.biSize = 40;
	bih.biWidth = bmInfo.bmWidth;
	bih.biHeight = bmInfo.bmHeight;
	bih.biPlanes = 1;
	bih.biBitCount = 24;
	bih.biCompression = BI_RGB;
	bih.biSizeImage = bmDataSize;
	bih.biXPelsPerMeter = 0;
	bih.biYPelsPerMeter = 0;
	bih.biClrUsed = 0;
	bih.biClrImportant = 0;
	::GetDIBits(dc, hBitmap, 0, bmInfo.bmHeight, bmData, (BITMAPINFO*)&bih, DIB_RGB_COLORS);//获取位图数据部分
	HANDLE hFile = CreateFile(bmpPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, 0);//创建文件
	DWORD dwSize;
	WriteFile(hFile, (void *)&bfh, sizeof(BITMAPFILEHEADER), &dwSize, 0);//写入位图文件头
	WriteFile(hFile, (void *)&bih, sizeof(BITMAPINFOHEADER), &dwSize, 0);//写入位图信息头
	WriteFile(hFile, (void *)bmData, bmDataSize, &dwSize, 0);//写入位图数据
	::CloseHandle(hFile);//关闭文件句柄
}


第九十个FindWindowEx查找一个父窗口里的子窗口（根据子窗口类名，窗口名），函数返回子窗口句柄


函数定义：HWND FindWindowEx


（HWND hwndParent,//父窗口句柄


HWND hwndChildAfter,//子窗口句柄，指明Z序


LPCTSTR lpszClass,//窗口类名


LPCTSTR lpszWindow//窗口名称


）;


第一个参数hwndParent如果为NULL，则以桌面窗口为父窗口，此时，这个函数与FindWindow函数一样,


第二个参数，子窗口句柄，如果为NULL，则从主窗口的第一Z序开始查找，否则从该子窗口的Z序开始查找。


后面两个个参数跟FindWindow的两个参数意思一样。


例子：模仿按钮单击


查找一个父窗口下特定的按钮，然后用SendMessage函数给父窗口发送按钮被单击的消息


假设这个父窗口名为"abc", 其下有一个名为"确定"的按钮


提示：


控件消息是：WM_COMMAND，wParam参数低十六位存储存控件ID号，高十六位存储有具体控件消息（如BN_CLICKED，单击），lParam存储控件窗口句柄，控件ID号可以用GetDlgCtrlID函数获取，该函数根据控件窗口句柄，获取控件ID号。


#include<windows.h>
int main()
{
	HWND wnd = ::FindWindow(NULL, "abc");
	HWND ButtonWnd = ::FindWindowEx(wnd, NULL, NULL, "确定");//查找名为"确定"的子窗口句柄
	int CtrlID = ::GetDlgCtrlID(ButtonWnd);//获得控件ID
	SendMessage(wnd, WM_COMMAND, MAKEWPARAM(CtrlID, BN_CLICKED), LPARAM(ButtonWnd));//发送控件消息
	return 0;
}





http://hi.baidu.com/3582077/item/90827a51687894abacc8571b


第九十一个CreateFont创建一种字体，函数返回字体句柄HFONT


HFONT CreateFont(
	int nHeight,//字符高度
	int nWidth,//字符宽度，nHeight 和nWidth参数指明字体大小
	int nEscapement,//文本显示时的倾斜角度，以字符框左上角为原点，负数表示顺时针旋转，正数逆时针（如2700，旋转270度）
	int nOrientation,//字符显示时的倾斜角度。nEscaperment和nOnentation这两个参数一般取0就可以了。
	int fnWeight,//字体重量，即字体粗细程序，范围在0到1000之间。填FW_NORMAL就行了
	DWORD fdwItalic,//指明字体是否倾斜，true表明是斜体字，false则不是
	DWORD fdwUnderline,//指明字体是否具有下划线，true有，false没有。
	DWORD fdwStrikeOut,//指明字体是否显示删除线，取值同上。
	DWORD fdwCharSet,//指明字符集，填DEFAULT_CHARSET（默认）
	DWORD fdwOutputPrecision, //指定输出精度，填OUT_DEFAULT_PRECIS（默认）
	DWORD fdwClipPrecision,//指定裁剪精度，填CLIP_DEFAULT_PRECIS（默认）
	DWORD fdwQuality,//字符输出质量，填DEFAULT_QUALITY（默认）
	DWORD fdwPitchAndFamily,//字符间距，填DEFAULT_PITCH(默认）
	LPCTSTR lpszFace//字体名称，如"宋体","黑体".
);


标准创建字体的语句：


HFONTFont = CreateFont(20, 20, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
	CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH,
	"宋体");


后面的函数将会有例子


第九十二个BeginPath开启一个路径


需设备DC作参数，开启一个路径后，再调用画图函数在开启路径的DC上的进行操作，则没有实质图形，仅仅是路径，这些路径是看不见，但它确实存在。但可以调用其它函数对路径进行操作, 如StroekPath函数，用当前画笔描绘路径。这里还要说明一点，并不是所有的画图函数支持路径的。下面给出支持路径的画图函数：


AngleArc


Arc画弧函数


ArcTo
Chord
CloseFigure
Ellipse画椭圆
ExtTextOut输出文本
LineTo 画直线，与MoveToEx函数结合使用
MoveToEx 画直线
Pie画饼图函数
PolyBezier
PolyBezierTo
PolyDraw
Polygon
Polyline
PolylineTo
PolyPolygon
PolyPolyline
Rectangle画矩形
RoundRect圆色矩形
TextOut输出文本


当不需要再用上面这些函数绘制路径后，就用EndPath函数结束路径


第九十三个StrokePath用当前笔描绘路径


函数只有一个参数，DC句柄。


例子：在一个窗口显示镂空字


#include<windows.h>
int main()
{
	HWND wnd = FindWindow(NULL, "无标题.txt - 记事本");
	HDC dc = GetDC(wnd);
	HFONTFont = CreateFont(50, 50, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH,
		"宋体");//创建字体
	HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));//创建红色画笔
	SelectObject(dc, pen);//选入画笔
	SelectObject(dc, Font);//选入字体
	SetBkMode(dc, TRANSPARENT);//设置文本背景颜色为透明
	while (1)
	{
		BeginPath(dc);//开启路径
		TextOut(dc, 0, 0, "ABC", 3);
		EndPath(dc);//结束路径
		StrokePath(dc);//用当前画笔描绘路径
		Sleep(300);
	}
	return 0;
}


第九十四个SetWindowRgn设置窗口显示区域


函数定义 : int
	SetWindowRgn(
		HWND hWnd,//要设置的窗口句柄
		HRGN hRgn,//区域句柄，设置的窗口显示区域将由区域句柄决定。
		BOOL bRedraw//指明窗口是否重画，true重画


	);


SetWindowRgn函数用于设置一个窗口的显示区域，所以必须提供给这个函数一个区域，而该函数的第二个参数hRgn就指明了这个区域。


区域句柄可以通过CreateRectRgn函数（创建一个矩形区域）获取。类似的函数还有CreateEllipticRgn（创建一个圆形区域）。


例子：让一个窗口只显示其四分之一，（什么窗口为例就不需要说了吧）


#include<windows.h>
int main()
{
	HWND wnd = ::FindWindow(NULL, "无标题.txt - 记事本");
	RECT rect;
	GetWindowRect(wnd, &rect);//整个窗口，不是客户区域
	int Width = rect.right - rect.left;
	int Height = rect.bottom - rect.top;
	HRGN hRgn = ::CreateRectRgn(0, 0, Width / 4, Height / 4);//有兴趣的朋友可以把这句的CreateRectRgn函数换成CreateEllipticRgn试试
	SetWindowRgn(wnd, hRgn, true);
	return 0;
}


怎么样，窗口是不是只显示了四分之一，但此时用GetClientRect函数获得窗口大小是多少呢，窗口的大小依旧没变，跟原来的一样
SetWindowRgn函数只是设置窗口显示区域，并不是设置窗口大小.


那要如何获得窗口显示区域部分呢，用GetWindowRgn函数，该函数获取窗口显示区域句柄。


第九十五个CombineRgn合并两个区域


函数定义：int


CombineRgn(


	HRGN hDestRgn, //接收新区域的句柄


	HRGN hSrcRgn1,//要合并的区域句柄1


	HRGN hSrcRgn2//要合并的区域句柄2


	int nCombineMode//指明具体如何合并


);


这里要注意参数hDesRgn, 必须是一个已创建的区域句柄


下面是nCombineMode参数的取值以及各取值所获取的部分


RGN_AND 两个区域的重叠部分


RGN_OR 组合两个区域


RGN_DIFF hSrcRgn1未重叠的部分


RGN_XOR hSrcRgn1和hSrcRgn2未重叠的部分


RGN_COPY 拷贝hSrcRgn1(hSrcRgn1部分）


	例子：用FillRgn函数填充两个区域的共同部分


#include<windows.h>
	int main()
{
	HWND wnd = FindWindow(NULL, "无标题.txt - 记事本");
	HDC dc = GetDC(wnd);
	HRGN hRect = CreateRectRgn(0, 0, 200, 200);
	HRGN hElliptic = CreateEllipticRgn(100, 100, 250, 250);
	HRGN ComRgn = CreateRectRgn(0, 0, 0, 0);
	CombineRgn(ComRgn, hRect, hElliptic, RGN_AND);
	while (1)
	{
		FillRgn(dc, ComRgn, CreateSolidBrush(RGB(255, 0, 0)));//调用FillRgn函数填充区域
		Sleep(300);
	}
	return 0;
}


第九十六个GetPixel根据DC获取一个坐标点的颜色值


该函数第一个参数，是DC，后两个参数指明坐标点，函数返回该坐标点的颜色值，在这里要说明的是，最好不要直接获取DC里颜色值，用CreateCompatibleDC函数创造一个兼容的DC，然后再用BitBlt函数把DC里的数据复制到兼容的DC里，再用GetPixel函数获取兼容DC里的颜色值。这样的话，就不会出什么问题。


如：


HWND wnd = FindWindow(NULL, "无标题.txt- 记事本");


HDC dc = GetDC(wnd);


HDC memDC = CreateCompatibleDC(dc);


RECT rect;


GetClientRect(wnd, &rect);


HBITMAP bmp;
bmp = CreateCompatibleBitmap(dc, rect.right, rect.top);
SelectObject(memDC, bmp);
BitBlt(memDC, 0, 0, rect.right, rect.top, dc, 0, 0, SRCCOPY);


COLORREF clr = GetPixel(memDC, 10, 10);//获取客户区坐标点10.10的颜色值


例子：不规则位图窗口


说明：


要创建一个不规则的位图窗口，首先必须得获得这个不规则位图的区域，是用什么方法呢，大家看一下StretchBlt函数里的flower1位图，


花部分是黑色，其它部分是白色，这样我们可以用GetPixel函数判断哪些像素是黑色, 知道了哪些像素是黑色，我就是可以用CreateRectRgn函数创建一个像素区域的区域句柄，再用CombineRgn函数把这个区域添加到一个主区域里。这样就可以获取花部分的区域了


代码如下：（以StretchBlt函数里的两副位图为例）


#include<windows.h>
int main()
{


	HWND wnd = FindWindow(NULL, "无标题.txt- 记事本");
	HBITMAPhBmp1 = (HBITMAP)LoadImage(NULL, "e:\\flower1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	HBITMAPhBmp2 = (HBITMAP)LoadImage(NULL, "e:\\flower2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BITMAP bmInfo;
	GetObject(hBmp1, sizeof(BITMAP), &bmInfo);
	::MoveWindow(wnd, 0, 0, bmInfo.bmWidth, bmInfo.bmHeight, TRUE);
	HRGN bmRGN = CreateRectRgn(0, 0, 0, 0);
	HDC dc = GetWindowDC(wnd);
	HDC memDC;
	memDC = CreateCompatibleDC(dc);
	SelectObject(memDC, hBmp1);
	for (int y = 0; y < bmInfo.bmHeight; y++)
		for (int x = 0; x < bmInfo.bmWidth; x++)
		{
			if (GetPixel(memDC, x, y) == 0)//如果是黑色
			{


				HRGN pRgn = CreateRectRgn(x, y, x + 1, y + 1);//创建区域
				CombineRgn(bmRGN, bmRGN, pRgn, RGN_OR);//把pRgn添加到bmRGN区域里
			}
		}
	SetWindowRgn(wnd, bmRGN, TRUE);
	while (1)
	{
		SelectObject(memDC, hBmp1);
		StretchBlt(dc, 0, 0, bmInfo.bmWidth, bmInfo.bmHeight, memDC,
			0, 0, bmInfo.bmWidth, bmInfo.bmHeight, SRCAND);//按位与运算合并DC
		SelectObject(memDC, hBmp2);
		StretchBlt(dc, 0, 0, bmInfo.bmWidth, bmInfo.bmHeight, memDC,
			0, 0, bmInfo.bmWidth, bmInfo.bmHeight, SRCPAINT);//按位或运算合并DC
		Sleep(300);
	}
	return 0;
}


运行效果：


对应的函数还有SetPixel这个是设置一个像素点的颜色值


第九十七个PathToRegion将一个DC里的路径转换成选区（HRGN)


函数只有一个参数，是转换路径的DC，函数返回区域句柄。


例子：设置一个文字窗口


#include<windows.h>
int main()
{
	HWND wnd = FindWindow(NULL, "无标题.txt - 记事本");
	HFONTFont = CreateFont(60, 60, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH,
		"宋体");//创建一种字体
	HDC dc = GetDC(wnd);
	BeginPath(dc);//请求路径
	SelectObject(dc, Font);
	SetBkMode(dc, TRANSPARENT);
	TextOut(dc, 0, 0, "文字窗口", 8);//形成路径
	EndPath(dc);//结束路径
	HRGN rgn = ::PathToRegion(dc);//将路径转换成选区，rgn接收该区域
	SetWindowRgn(wnd, rgn, TRUE);//设置窗口显示区域
	return 0;
}


第九十八个GetWindowLong获取一个窗口的信息


函数定义：LONG GetWindowLong(HWND hWnd，intnlndex);


第二个参数nIndex指明获取窗口什么信息，它可以有以下取值：（来自百度百科）


GWL_EXSTYLE；获得扩展窗口风格 对应着CreateWindowEx函数的DWORD wExStyle参数


GWL_STYLE：获得窗口风格 对应着CreateWindowEx函数的DWORD dwStyle参数


GWL_WNDPROC：获得窗口过程的地址，对应着WNDCLASS结构的 pfnWndProc成员


GWL_HINSTANCE WNDCLASS结构的hInstance成员


GWL_HWNDPAAENT：如果父窗口存在，获得父窗口句柄。


GWL_ID : 获得窗口标识（窗口ID）


	函数的返回值指明窗口信息，依据nIndex取值而定


	第九十八个SetWindowLong设置一个窗口信息


	函数定义：LONG SetWindowLong（HWND hWnd，int nlndex，LONG dwNewLong);


nIndex参数的解释跟GetWindowLong函数的nIndex参数一样，dwNewLong参数指明要设置的信息，跟GetWindowLong函数的返回值相对应。


例子：去掉一个窗口的标题栏


#include<windows.h>
int main()
{
	HWND wnd = FindWindow(NULL, "无标题.txt - 记事本");
	LONG dw = GetWindowLong(wnd, GWL_STYLE);//获取窗口风格
	dw ^= WS_CAPTION;//去掉dw的WS_CAPTION(标题)属性
	SetWindowLong(wnd, GWL_STYLE, dw); //设置窗口风格
	ShowWindow(wnd, SW_MINIMIZE);//最小化窗口
	return 0;
}


第九十九个CreateFileMapping创建一个内存文件映射或共享内存（函数返回文件映射对象句柄）


将一个文件映射到内存，对映射的这块内存的读写，就跟磁盘中的文件读写是一样的，由于文件内存映射处理磁盘的文件时，省去了文件I / O操作，因此特别适合处理较大的文件。


函数定义：HANDLE
CreateFileMapping(
	HANDLE hFile,//要映射的文件句柄，通过CreateFile函数获得，如果为INVALID_HANDLE_VALUE，则表明创建的是共享内存


	LPSECURITY_ATTRIBUTES lpFileMappingAttributes,//它指明返回的句柄是否可以被子进程所继承,一般为NULL
	DWORD flProtect,//指明映射打开方式，PAGE_READONLY（只读），PAGE_READWRITE（读写）
	DWORD dwMaximumSizeHigh,//文件映射的最大长度的高32位
	DWORD dwMaximumSizeLow,//文件映射的最大长度的低32位,
	LPCWSTR lpName//文件内存映射对象的名称，可以为NULL
);


由于文件的在最大长度可能会超过32位大小，所以这个函数用两个32位变量（dwMaximumSizeHigh和dwMaximumSizeLow)来表示一个文件的最大长度，当这两个参数的取值都为0时，也就是文件最大长度为0时，就用磁盘文件的实际长度。


第一百个MapViewOfFile将一个文件映射对象映射到当前应用程序的地址空间


函数定义：LPVOID
MapViewOfFile(
	HANDLE hFileMappingObject,//文件映射对象的句柄，CreateFileMapping函数获得
	DWORD dwDesiredAccess,//映射方式，FILE_MAP_WRITE (读写）FILE_MAP_READ（只读）
	DWORD dwFileOffsetHigh,//文件中映射起点的高32位地址 
	DWORD dwFileOffsetLow,//文件中映射起点的低32位地址 ，高低可为0
	DWORD dwNumberOfBytesToMap//文件中要映射的字节数。为0映射整个文件映射对象 
);


函数返回文件映射在内存中的起始地址。


例子：读写一个文件（假设E盘下有一个名为a.txt的文件，内容为0123456789）


#include<windows.h>
#include<stdio.h>
int main()
{
	HANDLE hFile = CreateFile("e:\\a.txt", GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);//以读写方式打开文件
	HANDLE hMap = ::CreateFileMapping(hFile, NULL, PAGE_READWRITE, NULL, NULL, NULL);
	LPVOID lpBase = ::MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, 0);
	for (int i = 0; i < 10; i++)//读映射内存中的数据
		printf("%c ", ((char *)lpBase)[i]);
	printf("\n");
	for (i = 0; i < 10; i++)//写入数据到映射内存中
		((char *)lpBase)[i] = L'A' + i;
	return 0;
}


此时再去打开E盘下a.txt文件，是不是里面的内容全变为"A"了。


这里要说明的是，文件打开方式，映射打开方式，映射方式必须是一致的，不能以只读打开文件，又以只写映射打开文件





http://hi.baidu.com/3582077/item/33998ace7814e326a0b50a19


第一百零一个OpenFileMapping获取CreateFileMapping函数创建的文件映射对象句柄


函数定义：HANDLE
OpenFileMappingW(
	DWORD dwDesiredAccess,//取值参考MapViewOfFile函数的dwDesiredAccess参数
	BOOL bInheritHandle,//依据CreateFileMapping函数的lpFileMappingAttributes参数而定，不能被新进程继承，为FALSE
	LPCWSTR lpName//指明获取哪个文件映射对象句柄，对应着CreateFileMapping函数的lpName参数
);


函数返回文件映射对象句柄。


例子：两进程间传递数据


进程1程序代码：


#include<windows.h>
#include<stdio.h>
int main()
{
	char Data[11] = "0123456789";
	HANDLEhMap = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 11, "ShareMemory");
	LPVOID lpBase = ::MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, 0);
	strcpy((char *)lpBase, Data);//写入数据
	while (1)
	{
		Sleep(2000);
	}
	return 0;
}
进程2程序代码：


#include<stdio.h>
#include<windows.h>
int main()
{
	HANDLE hMap = ::OpenFileMapping(FILE_MAP_WRITE, FALSE, "ShareMemory");
	LPVOID lpBase = ::MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, 0);
	printf("ShareMemory Data:%s\n", lpBase);//输出数据
	return 0;
}


第一百零二个CopyMemory复制一段内存


函数定义：　VOID CopyMemory(
	PVOID Destination, //目的地址
	CONST VOID *Source, //源地址
	DWORD Length //复制多少字节
);
这个函数跟C语言的memcpy函数一样，这里仅举个例子：
#include<stdio.h>
#include<windows.h>
int main()
{
	DWORD dwDestin = 0;
	DWORD dwSource = 120;
	CopyMemory((void *)&dwDestin, (void *)&dwSource, sizeof(DWORD));
	printf("%d\n", dwDestin);
	return 0;
}


第一百零三个SetParent设置（更改）一个子窗口的父窗口


该函数有两个参数，第一个是子窗口的句柄，第二个是父窗口的句柄。


如果父窗口句柄为空，则以桌面窗口作为父窗口


例子：把记事本里状态栏的父窗口改为编辑框窗口


用spy++查看记事本编辑框窗口的类名为"Edit", 状态栏为"msctls_statusbar32"(可能会有差异，具体可以用Spy++查看）


#include<windows.h>
	int main()
{
	HWND wnd = FindWindow(NULL, "无标题.txt - 记事本");
	HWND EditWnd = FindWindowEx(wnd, NULL, "Edit", NULL);//查找获取编辑框窗口句柄
	HWND StatusWnd = FindWindowEx(wnd, NULL, "msctls_statusbar32", NULL);//查找获取状态栏窗口句柄
	::SetParent(StatusWnd, EditWnd);//设置状态栏父窗口
	RECT rect;
	GetClientRect(StatusWnd, &rect);//获取状态栏客户区大小


	//移动状态栏窗口，如果编辑框窗口不是状态栏的父窗口，则状态栏是移不进编辑框窗口的
	MoveWindow(StatusWnd, 0, 0, rect.right, rect.bottom, TRUE);


	return 0;
}


第一百零四个OpenClipboard打开一个剪切板


剪切板是什么意思呢，可以把它看做一块内存，这块内存可以被任何进程调用相关函数进行读写。事实上，像我们平常的复制粘贴就是在读写这块内存，比如用选中一段文字，然后右击，选择复制，这时对应程序就会调用OpenClipboard函数打开剪切板，往里面写入数据，


当不再需要操作剪切板的时候就调用CloseClipboard函数关闭剪切板，剪切板不能同时被多个程序打开，也就是说如果其它程序已经调用OpenClipboard打开剪切板了，并且没有调用CloseClipboard关闭剪切板的话，那么其它程序调用OpenClipboard就会失败，这一点从下面的例子可以说明。


这个函数只有一个参数，是一个窗口句柄，也就是具体在哪个窗口里进行复制粘贴操作（剪切也算），如果为NULL，则跟调用这个函数的进程相关联。


例子：让粘贴复制失效


#include<windows.h>
int main()
{
	OpenClipboard(NULL);
	while (1)
		Sleep(1000);
}


由于这个程序打开了剪切板却并不关闭它，导致了其它程序无法调用OpenClipboard函数打开剪切板，无法打开剪切板，自然也就无法复制粘贴数据了


第一百零五个SetClipboardData写入一段数据到剪切板（设置剪切板的数据）


HANDLE SetClipboardData(UINT uFormat, HANDLE hMem);


像我们使用windows的复制粘贴的时候，不仅能复制文字，也能复制文件，图片等。所以uFormat指明要写入的是什么数据。


uFormat的常用取值如下：


CF_UNICODETEXT含有Unicode文字的内存块


CF_BITMAP与设备相关的位图格式。位图是通过位图句柄传送给剪切板的


CF_TEXT以NULL结尾的ANSI字符集字符串


第二个指向存储要写入的数据内存，注意，存储数据的内存必须是在堆中分配的。


例子1：写入ASCII字符串到剪切版


#include<windows.h>
#include<string.h>
int main()
{
	char *pData = new char[15];//在堆中申请内存
	strcpy(pData, "ABCDEFG");
	OpenClipboard(NULL);//打开剪切板
	EmptyClipboard();//清空剪切板的数据
	SetClipboardData(CF_TEXT, pData);//往剪切板里写入数据
	CloseClipboard();//关闭剪切板
	delete pData;
	return 0;
}


//随便到可以输入文字的地方，右击->粘贴看写入是否成功


例子2：写入宽字符串（Unicode）到剪切板


#include<string.h>
#include<windows.h>
int main()
{
	WCHAR *pData = new WCHAR[15];
	WCHAR str[15] = L"ABC我们D";//用L把ASCII转换成Unicode
	CopyMemory((void *)pData, (void *)str, sizeof(str));//相当于ASCII字符串处理函数strcpy
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, pData);
	CloseClipboard();
	return 0;
}


第一百零六个GlobalAlloc从堆中分配一定数目的字节数


HGLOBAL
WINAPI
GlobalAlloc(
	UINT uFlags,//分配属性(方式)
	DWORD dwBytes//分配多少字节
);


uFlags常用取值：
GMEM_FIXED 分配固定的内存, 返回值是一个指针


GMEM_MOVEABLE 返回值是一个内存句柄，可用GlobalLock函数根据一个内存句柄，返回内存句柄对应的首地址，并锁定内存中指定的内存块，对应的函数是：GlobalUnlock


对应的释放内存函数是GlobalFree，这里还是说明一个函数GlobalSize，这个根据内存句柄获得对应内存块大小


例子：GlobalAlloc函数应用


#include<stdio.h>
#include<windows.h>
int main()
{
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, 8);//按GEME_MOVEABLE方式分配内存


	DWORD dwSize = GlobalSize(hMem);//获取内存块大小
	int *pNumber = (int *)GlobalLock(hMem);//把内存句柄转换成内存首地址
	pNumber[0] = 5; pNumber[1] = 6;
	printf("内存块大小%d\n%d,%d\n", dwSize, pNumber[0], pNumber[1]);
	GlobalFree(hMem);//释放内存
	return 0;
}


第一百零七个GetClipboardData该函数获得剪切板里的数据，函数返回剪切板内存句柄


该函数只有一个参数，指明获取的是什么类型的数据，跟SetClipboardData函数的uFormat参数相对应，这里有一个问题，如何知道剪切板存储的是什么类型数据呢，用IsClipboardFormatAvailable函数，这个函数只有一个参数，如：IsClipboardFormatAvailable(CF_TEXT)


这个语句用于判断当前剪切板有没有含有CF_TEXT数据，如果有的话，返回真（TRUE），否返回假。这个函数不用事先打开剪切板，也可以正常调用。


注意如果如果剪切板的数据是CF_UNICODETEXT形式的，用CF_TEXT类型打开也是可以的，因为windows系统会自动进行转换。


例子：获取剪切板里的CF_TEXT数据（先随便复制一段文字）


#include<stdio.h>
#include<windows.h>
int main()
{
	if (IsClipboardFormatAvailable(CF_TEXT))//判断剪切板里是否有CF_TEXT数据
	{
		::OpenClipboard(NULL);
		HGLOBAL hGlobal = GetClipboardData(CF_TEXT);//以CF_TEXT方式打开剪切板
		char *pGlobal = (char *)GlobalLock(hGlobal);//获得剪切板内存的首地址，直接转换也可以，如(char *)hGlobal
		printf("%s\n", pGlobal);//输出剪切板里的文字


		GlobalUnlock(hGlobal);
		CloseClipboard();
	}
	return 0;
}


第一百零八个Shell_NotifyIcon在任务栏里注册图标（任务栏托盘菜单）


(PS：今天看了一下以前写的这个函数，我描述这个函数为托盘菜单，今天来看，似乎压根就跟菜单没关系，我想，应该是那时候是在MFC里看到这个函数，那个例子是做一个托盘菜单，我就用了托盘菜单了，却没有实现托盘菜单的功能，不过，并不影响理解这个函数用法，以及它的意思，我也较烦）


	函数定义：Shell_NotifyIcon(DWORD dwMessage, PNOTIFYICONDATAWlpData);


要想注册一个托盘菜单，首先你得提供一些信息，如在任务栏要显示的图标，系托盘菜单属于哪个窗口（严格来说，是托盘菜单产生的消息，发送给哪个窗口）


而这些信息就由Shell_NotifyIcon函数的第二个参数lpData指明。它是一个NOTIFYICONDATAW结构指针。


NOTIFYICONDATAW结构定义及各成员意思如下：


typedef struct _NOTIFYICONDATAW {
	DWORD cbSize;//指明NOTIFYICONDATA结构大小，用sizeof(NOTIFYICONDATA)给它赋值。
	HWND hWnd;//窗口句柄，由鼠标在托盘图标产生的消息将发送给这个窗口
	UINT uID;//标识托盘菜单的唯一ID号。
	UINT uFlags;//指明结构中哪些成员有效，可以是NIF_ICON（对应hIcon), NIF_MESSAGE（对应uCallbackMessage),


	//NIF_TIP(对应 szTip)，可以用|按位或运算符结合在一起。
	UINT uCallbackMessage;//自定义消息，鼠标在托菜图标上产生的行为将发送这个消息给hWnd成员对应的窗口
	HICON hIcon;//图标句柄，
	WCHAR szTip[64];//鼠标停留在托盘图标上产生的提示消息内容
} NOTIFYICONDATA, *PNOTIFYICONDATA;


dwMessage参数指明要进行的操作，常用取值有NIM_ADD（添加托盘菜单），NIM_DELETE（删除一个托盘菜单），NIM_MODIFY （修改一个托盘菜单）


了解了上面些我们来简单的在任务栏上显示一个托盘菜单的图标，其它什么也不做。


假设e盘下有一个名为"i.ico"的图标


代码如下：


#include<windows.h>
int main()
{
	NOTIFYICONDATA notify;//定义一个托盘菜单信息结构
	notify.cbSize = sizeof(NOTIFYICONDATA);//设置结构大小
	notify.hIcon = (HICON)LoadImage(NULL, "e:\\i.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE);//设置图标句柄
	notify.uFlags = NIF_ICON;//指明哪些成员有效
	::Shell_NotifyIcon(NIM_ADD, &notify);//添加托盘菜单
	while (1)
	{
		Sleep(1000);//避免程序退出，自动卸载托盘菜单
	}
	return 0;
}


怎么样任务栏是不是有一个图标显示了，但此时，用鼠单击，或双击任务上的图标都没反应。


如果想响应鼠标操作消息的话，得使 NOTIFYICONDATA结构的uCallbackMessage成员有效，这样当鼠标在托盘菜单图标上单击或双击后，就会产生uCallbackMessage成员对应的消息。而且还必须指定窗口句柄，不然产生了这个消息，发送给哪个窗口呢。


例子2：完整的托盘菜单应用


完整应用，必须得有自己的窗口，新建一个 “Win32 Application"工程。如果对用API函数创建窗口不了解的话，可以参考常用函数CreateWindow.


#include<windows.h>
#include<string.h>
//在WM_USER的基础上定义一个消息类型，用于托盘与窗口之间的消息传递
#define WM_TRAYMESSAGE WM_USER+25 
LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);//函数声明
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASS wndcls; //定义一个存储窗口信息WNDCLASS变量
	wndcls.cbClsExtra = 0; //默认为0
	wndcls.cbWndExtra = 0; //默认为0
	wndcls.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); //背景画刷
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW); //光标
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR); //窗口图标
	wndcls.hInstance = hInstance; //应用程序实例句柄由WinMain函数传进来
	wndcls.lpfnWndProc = WinSunProc; //窗口消息处理函数
	wndcls.lpszClassName = "windowclass"; //窗口类名
	wndcls.lpszMenuName = NULL; //窗口菜单名，没有菜单，为NULL
	wndcls.style = CS_HREDRAW | CS_VREDRAW;//窗口类型，CS_HREDRAW和CS_VERDRAW 表明
	//当窗口水平方向垂直方向的宽度变化时重绘整个窗口
	RegisterClass(&wndcls); //把窗口信息提交给系统，注册窗口类
	HWND hwnd; //用以存储CreateWindow函数所创建的窗口句柄
	hwnd = CreateWindow("windowclass", "托盘菜单应用",
		WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);//创建窗口
	NOTIFYICONDATAnotify;//定义一个托盘菜单信息结构
	notify.cbSize = sizeof(NOTIFYICONDATA);//设置结构大小
	notify.hIcon = (HICON)LoadImage(NULL, "e:\\i.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE);//设置图标句柄
	notify.hWnd = hwnd;//接收消息的窗口句柄
	strncpy(notify.szTip, "托盘菜单", sizeof("托盘菜单"));
	notify.uCallbackMessage = WM_TRAYMESSAGE;//托盘菜单将发送这个消息给窗口
	notify.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;//指明哪些成员有效
	::Shell_NotifyIcon(NIM_ADD, &notify);//添加托盘菜单
	ShowWindow(hwnd, SW_SHOWNORMAL);//窗口创建完了，显示它
	UpdateWindow(hwnd); //更新窗口，让窗口毫无延迟的显示
	MSG msg;//消息结构类型
	while (GetMessage(&msg, NULL, 0, 0))//获取消息
	{
		TranslateMessage(&msg); //此函数用于把键盘消息(WM_KEYDOWN,WM_KEYUP)转换成字符消息WM_CHAR
		DispatchMessage(&msg); //这个函数调用窗口过程处理函数，并把MSG里的信息处理后传给过程函数的四个参数
	}
	::Shell_NotifyIcon(NIM_DELETE, &notify);//卸载托盘菜单
	return 0;
}
LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_SYSCOMMAND:
		if (wParam == SC_MINIMIZE)//最小化了窗口
		{
			ShowWindow(hwnd, SW_HIDE);//隐藏窗口
		}
		else
		{
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
		break;
	case WM_TRAYMESSAGE:
		if (lParam == WM_LBUTTONDBLCLK)//双击托盘菜单图标,鼠标消息在lParam参数里
		{
			ShowWindow(hwnd, SW_RESTORE);//显示窗口
		}
		break;
	case WM_CLOSE://用户关闭了窗口
		DestroyWindow(hwnd);//销毁窗口，并发送WM_DESTROY消息
		break;
	case WM_DESTROY://如果窗口被销毁
		PostQuitMessage(0);//让进程退出
		break;
		//未处理的消息通过DefWindowProc函数交给系统处理
	default:return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}


	return 0;
}


第一百零九个FindResource从应用程序模块句柄找出一个资源


资源就是MFC里的资源，像位图，图标，对话框等这些资源都包含在exe文件里，如果看过PE文件结构分析及应用的话，应该会容易理解。


这个函数就是定位一个资源在模块里的位置。


函数定义：HRSRC FindResource(HMODULE hModule,//应用程序模块句柄，NULL表示本模块句柄


	LPCTSTR lpName,//资源名


	LPCTSTR lpType//资源类型


);


其中第一个参数hModule应用程序模块句柄, 自身模块填NULL就行，如果想获取其它正在运行的应用程序模块，就用GetModuleHandle函数。


资源名就像资源的ID号一样，比如一个MFC的一个资源ID号是147，那么此参数应该是这样的"#147"，或用MAKEINTRESOURCE宏转换


如：MAKEINTRESOURCE(147)


lpType用于表明资源类型，它是对话框？菜单？位图？还是自定义资源。。。


常用取值如下：


#define RT_CURSOR MAKEINTRESOURCE(1) //光标
#define RT_BITMAP MAKEINTRESOURCE(2) //位图
#define RT_ICON MAKEINTRESOURCE(3)//图标
#define RT_MENU MAKEINTRESOURCE(4)//菜单
#define RT_DIALOG MAKEINTRESOURCE(5)//对话框
#define RT_STRING MAKEINTRESOURCE(6)//字符串
#define RT_FONTDIR MAKEINTRESOURCE(7)
#define RT_FONT MAKEINTRESOURCE(8)//字体
#define RT_ACCELERATOR MAKEINTRESOURCE(9)
#define RT_RCDATA MAKEINTRESOURCE(10)
#define RT_MESSAGETABLE MAKEINTRESOURCE(11)


#define DIFFERENCE 11
#define RT_GROUP_CURSOR MAKEINTRESOURCE((DWORD)RT_CURSOR + DIFFERENCE)//光标组
#define RT_GROUP_ICON MAKEINTRESOURCE((DWORD)RT_ICON + DIFFERENCE)//图标组
#define RT_VERSION MAKEINTRESOURCE(16)
#define RT_DLGINCLUDE MAKEINTRESOURCE(17)


第一百一十个LoadResource根据资源指向句柄（HRSRC）把资源装载到内存。


函数返回资源所在内存句柄（HGLOBAL），可以用LockResource根据内存句柄，获取内存首地址


函数定义：


HGLOBAL LoadResource(HMODULE hModule, HRSRC hResiInfo);


hModule参数同FindResource对应的参一样，模块句柄，hResiInfo参数对应FindResource函数返回的值


LockResource函数定义：LPVOIDLockResource(HGLOBAL hResDate);
hResDate参数对应LoadResource函数返回的值





http://hi.baidu.com/3582077/item/eed4cc5fa6fff43795eb0508


第一百一十一个SizeofResource获取一个资源的大小


函数定义：DWORD SizeofResource(


	HMODULE hModule,//模块句柄，同FindResource,LoadResource的模块句柄一样


	HRSRC hResInfo//资源位置句柄,是FindResource函数返回的句柄


);


例子：自定义资源，EXE文件包含DLL，双击该EXE文件释放里面的DLL文件到当前目录


首先我们新建一个控件台工程，你也可以新建一个WIN32工程，由于这里建的不是MFC工程，所以还得往工程里添加资源文件，步骤是文件->新建，在弹出的对话框中选择“文件”选项标签，然后选中“资源脚本”，我们要建的就是这个文件，取名、确定、完成。


接着我们进入资源视图（ResourceView), 右击资源文件，选择引入(记得把文件类型选所有），选择一个DLL文件，点引入。这时候会弹出一个对话框，提示你给自定义资源类型取类型名，记住这个类型名对应着FindResource函数的第三个参数lpType，取名为DLL，确定，接着我们只要查看一下这个自定义资源的ID号，就可以去敲代码了。方法是右击资源文件，选择"资源符号", 这里我查看的对应ID号是101。好了进入代码编辑区，键入如下代码：


#include<windows.h>
	int main()
{
	HRSRC hRsrc = FindResource(NULL, MAKEINTRESOURCE(101), "DLL");//查找资源位置
	DWORD dllSize = SizeofResource(NULL, hRsrc);//获取资源大小
	HGLOBAL hGlobal = LoadResource(NULL, hRsrc);//加载资源到内存
	LPVOID pBuffer = LockResource(hGlobal);//获取内存首地址
	char pathName[100];
	GetModuleFileName(NULL, pathName, 100);//获得应用程序完整路径名
	int i = 0;
	while (pathName[i] != '\0') i++;//计算路径名字符串最后的位置
	//把exe改成dll，然后创建文件
	pathName[i - 1] = 'l';
	pathName[i - 2] = 'l';
	pathName[i - 3] = 'd';
	HANDLE hFile = CreateFile(pathName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);//创建文件
	DWORD dwSize;
	WriteFile(hFile, pBuffer, dllSize, &dwSize, NULL);//写入数据
	return 0;
}


运行，然后把生成的EXE程序随便复制到一个目录下，双击运行一下。看不是在同一目录下释放出了一个DLL文件。


这可以应用到任何文件上，像可以让一个EXE文件里包含两个EXE文件，当执行这个EXE文件后，会释放出两个EXE文件，然后删除自身。


第一百一十二个SetLayeredWindowAttributes设置窗口透明度


函数定义：BOOL SetLayeredWindowAttributes(
	HWND hwnd,//要设置的窗口句柄
	COLORREF crKey,//如果窗口一个像素颜色值等于crKey，那么这个像素将是透明的
	BYTE bAlpha,//取值范围0到255，0表示全透明，255表示不透明
	DWORD dwFlags//指定crKey还是bAlpha值有效，LWA_COLORKEY（0x1)指定crKey值有效，bAlpha值无效，


	//LWA_ALPHA（0x2)表 示 bAlpah值有效，crKey值无效。LWA_COLORKEY|LWA_ALPHA表示两者都有效
);


想要调用SetLayeredWindowAttributes设置窗口透明度，必须让窗口具有WS_EX_LAYERED（0x80000)扩展样式，可用SetWindowLong函数设置，该函数用法参考API 常用函数第九十八个。而SetLayeredWindowAttributes函数在动态链接库user32.dll里面，关于调用动态链接库里的函数请参考http://hi.baidu.com/3582077/blog/item/8471dcdd82e15e205882dd68.html，本例采用第二种方法用LoadLibrary，这个函数的用法不懂的可以参考 API常用函数第四十九个。


这里的窗口依旧以无标题记事本为例


#include<windows.h>
int main()
{
	HWND wnd = FindWindow(NULL, "无标题.txt - 记事本");
	SetWindowLong(wnd, GWL_EXSTYLE, GetWindowLong(wnd, GWL_EXSTYLE) | 0x80000);
	typedef BOOL(WINAPI *FSetLayeredWindowAttributes)(HWND, COLORREF, BYTE, DWORD);
	FSetLayeredWindowAttributes SetLayeredWindowAttributes;
	HINSTANCE hInst = LoadLibrary("User32.DLL");
	SetLayeredWindowAttributes = (FSetLayeredWindowAttributes)GetProcAddress(hInst, "SetLayeredWindowAttributes");
	int value = 0;
	while (1)
	{
		if (value == 256) value = 0;
		SetLayeredWindowAttributes(wnd, RGB(0, 0, 0), value, 0x2);//0x2 让第二个参数无效。
		value++;
		Sleep(50);
	}
	return 0;
}
第一百一十三个SetROP2设置DC画图模式


通常情况下，如果不调用SetROP2函数设置画图模式，那么默认的DC画图模式就是R2_COPYPEN（直接用源值覆盖），以Rectangle函数来举例，选入一个红色画刷，如：


HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));


SelectObject(hdc, brush); 那么调用Rectangle在一个窗口里画一个0，0，100，100的矩形就是


Rectangle(hdc, 0, 0, 100, 100);


如果没调用Rectangle之前，窗口这部分区域全是绿色，


如下图：




(为了方便，把这个称为dest)


那么调用Rectangle之后，这部分区域应该是这样的：




（这个就称为src）


这两个区域每一个像素都有一个RGB颜色值，如0, 255, 0和255, 0, 0，而Rectangle所要做的就是合并这样两个区域(dest和src)，由于采用R2_COPYPEN画图模式，直接用src覆盖掉dest，那么最终在窗口里显示的结果应该全是红色，也就是每个像素值都是红色。


又如R2_MASKPEN模式，这个是采用按位与（AND）合并两幅图片。两张图片的对应像素颜色值进行按位与运算。


也就是RGB(0, 255, 0)&RGB(255, 0, 0)的结果就是窗口最终显示的像素颜色。


那么如果用SetROP2设置画图模式为R2_MASKPEN，再调用Rectangle，窗口显示的应该是这样：


红蓝按位与合并后的结果。RGB(0, 255, 0)&RGB(255, 0, 0)的结果是0，也就是颜色值RGB(0, 0, 0)黑色。


类似的，还有按位或，按位异或，取反等运算，现给出所有模式及运算解释（来自Programming Windowswith MFC）


R2_NOPdest = destR2_NOTdest = NOT destR2_BLACK dest = BLACKR2_WHITEdest = WHITER2_COPYPEN dest = srcR2_NOTCOPYPEN dest = NOTsrcR2_MERGEPENNOT dest = (NOT dest) OR srcR2_MASKPENNOT dest = (NOT dest) ANDsrcR2_MERGENOTPENdest = (NOT src) OR destR2_MASKNOTPEN dest = (NOT src) ANDdestR2_MERGEPEN dest = dest OR srcR2_NOTMERGEPEN dest = NOT(dest ORsrc)R2_MASKPEN dest = dest AND srcR2_NOTMASKPENdest = NOT(dest ANDsrc)R2_XORPENdest = src XOR destR2_NOTXORPENdest = NOT(src XOR dest)


例子：以R2_MASKPEN 画图模式在窗口里画一个矩形


#include<windows.h>
int main()
{


	HWND wnd = FindWindow(NULL, "无标题.txt- 记事本");
	HDC dc = GetWindowDC(wnd);
	HBRUSH brush = CreateSolidBrush(RGB(100, 255, 255));
	SelectObject(dc, brush);
	SetROP2(dc, R2_MASKPEN);
	while (1)
	{
		Rectangle(dc, 0, 0, 200, 200);
		Sleep(200);
	}
	return 0;
}


运行效果：




用另外几种模式试一下，看看结果又会有什么不同。


第一百一十四个SetMapMode设置DC映射模式
默认的模式是MM_TEXT, 一个单位等于一个像素, 也就是当你调用Rectangle等函数画图时, 参数的单位是像素, 如Rectangle(hdc, 0, 0, 100, 100); 此时的0, 0是窗口的左上角, 一个宽300, 高300像素的矩形.
而如果把模式换一下的话, 结果就不是这样了, 像MM_LOMETRIC模式的单位就是0.1毫米, 那么Rectangle(hdc, 0, 0, 100, 100)所画的矩形应该是100*0.1mm宽, 100 * 0.1mm高, 也就是1厘米宽高, 但真设置NM_LOMETRIC模式, 再调用Rectangle(hdc, 0, 0, 100, 100)后, 并不会在窗口里显示一个矩形, 这是为什么呢, 窗口所对应的坐标不同.
NM_TEXT模式下窗口左上角对应坐标点0, 0, 往右往下都是递增, 如下图:


而除了自定义模式, 和NM_TEXT模式, 窗口的坐标都是这样的 :


	那么如果窗口坐标处在这种模式下, 想在窗口里画矩形, Y坐标必须为是负数, 所以上面的Rectangle调用应该是这样Rectangle(0, 0, 100, -100); 而这里的单位是0.1mm


	下面给出各种模式及解释


	MM_TEXT 1 pixel


	MM_LOMETRIC 0.1 mm


	MM_HIMETRIC 0.01 mm


	MM_LOENGLISH 0.01 in.


	MM_HIENGLISH 0.001 in.


	MM_TWIPS 1 / 1440 in.(0.0007 in.)


	MM_ISOTROPIC User - defined(x and y scale identically)User - defined


	MM_ANISOTROPIC User - defined(x and y scale independently)User - defined


	in.是英寸的缩写.


	例子在一个窗口画一根5厘米长的直线，映射模式为MM_LOMETRIC


#include<windows.h>
	int main()
{


	HWND wnd = FindWindow(NULL, "无标题.txt- 记事本");
	HDC dc = GetDC(wnd);
	::SetMapMode(dc, MM_LOMETRIC);//设置映射模式
	while (1)
	{
		MoveToEx(dc, 0, -50, NULL);
		LineTo(dc, 500, -50);//500不是像素，单位是0.1mm
		Sleep(200);
	}
	return 0;
}
//用尺子去量一下那根线，看是不是五厘米，没尺子？没关系，用PS建一个
//五厘米的宽的图像，对比一下。


第一百一十五个DPtoLP将设备坐标转换成逻辑坐标


其实就是将MM_TEXT模式（以像素为单位）坐标点转换成当前模式下的坐标，比如在MM_TEXT模式下150，150这个坐标点位置在MM_LOMETRIC模式里是在哪里。也就是说50*0.1mm是多少像素。


先来看下面这个例子，将150，150这个在MM_TEXT模式下的坐标点转换成MM_LOMETRIC模式下对应的坐标点.


#include<windows.h>
#include<iostream.h>
int main()
{


	HWND wnd = FindWindow(NULL, "无标题.txt- 记事本");
	HDC dc = GetDC(wnd);
	POINT pt;
	pt.x = pt.y = 150;


	//设置当前模式，针对当前模式而转换，如果不设置，默认是MM_TEXT，MM_TEXT转MM_TEXT结果还是一样
	SetMapMode(dc, MM_LOMETRIC);


	DPtoLP(dc, &pt, 1);//dc是设备上下文，第二个参数是一个POINT指针，第三个指明数组数量。用于多个转换


	//如：POINTpt[2]={{100,100},{200,200}};DPtoLP(dc,pt,2);
	cout << pt.x << "," << pt.y << endl;
	return 0;
}
我这儿的输出结果是 469， - 469


具体依据电脑设置而定, 也就是说在MM_LOMETRIC模式下469， - 469这个坐标点和MM_TEXT模式下100，100这个坐标点的位置是相同的。


例子：在一个窗口里的两种模式下画同一长度的线


#include<windows.h>
int main()
{


	HWND wnd = FindWindow(NULL, "无标题.txt- 记事本");
	HDC dc = GetDC(wnd);
	POINT ptText[2] = { {0,50},{200,50} };//MM_TEXT模式下直线两点
	POINT ptLOME[2] = { {0,100},{200,100} };//MM_LOMETRIC模式下直线两点
	SetMapMode(dc, MM_LOMETRIC);//设置模式
	DPtoLP(dc, ptLOME, 2);//转换成MM_LOMETRIC对应的坐标点
	while (1)
	{
		MoveToEx(dc, ptLOME[0].x, ptLOME[1].y, NULL);
		LineTo(dc, ptLOME[1].x, ptLOME[1].y);
		SetMapMode(dc, MM_TEXT);//模式改回来
		MoveToEx(dc, ptText[0].x, ptText[1].y, NULL);
		LineTo(dc, ptText[1].x, ptText[1].y);
		Sleep(300);
		SetMapMode(dc, MM_LOMETRIC);//设置模式
	}
	return 0;
}


既然可以转过去，也当然可以转回来


DPtoLP用于把像素单位转换成其它模式单位，它的参数是以像素为单位的，转换后值的单位就是当前模式对应的单位，面LPtoDP正好相反，它参数的单位是以当前模式为准的，用于把其它模式下的坐标点转换成MM_TEXT模式下的。如模式MM_LOMETRIC，把上面的469， - 469转换成对应像素单位就是POINT pt = { 469,-469 }; LPtoDP(dc, &pt, 1);//记得要设置模式。





http://hi.baidu.com/3582077/item/eebe0ae316019bafcf2d4f08


第一百一十六个SetViewportOrgEx将窗口原点（0，0）映射到设备坐标点X, Y


函数定义：BOOL SetWindowOrgEx(HDC hdc, int X, int Y, LPPOINTlpPoint);


hdc是要映射的设备上下文，X, Y是要映射的坐标，lpPoint是窗口原点原来所映射的坐标，不需获取可为NULL。


比如这样一个语句：（假设hdc的设备模式为MM_TEXT）那么调用下面语句后


SetViewportOrgEx(hdc, 200, 200, NULL);


窗口的坐标就变成下面这样了：


看例子：


#include<windows.h>
int main()
{
	HWND wnd = FindWindow(NULL, "无标题.txt - 记事本");
	HDC hdc = GetDC(wnd);
	::SetViewportOrgEx(hdc, 200, 200, NULL);//设置坐标点200，200为窗口原坐标点0，0
	while (1)
	{
		Rectangle(hdc, 0, 0, 100, 100);
		Rectangle(hdc, 0, 0, -100, -100);
		Sleep(300);
	}
	return 0;
}


第一百一十七个SetWindowOrgEx将设备坐标点X, Y映射到窗口原点0，0


函数定义：BOOL SetWindowOrgEx(HDC hdc, int X, int Y, LPPOINTlpPoint);


跟SetViewportOrgEx的映射正好相反，这个函数的参数解释参照SetViewportOrgEx。


这里仅给出调用


SetWidnowOrgEx(hdc, 200, 200, NULL); 语句后的窗口坐标图。当然参数也可以为负数，可自行推算窗口坐标点。




第一百一十八个SetScrollPos设置滚动条位置


函数定义：int
SetScrollPos(
	HWND hWnd,//滚动条所在窗口句柄
	int nBar,//滚动条类型，参照SetScrollInfo函数
	int nPos,//滚动条位置
	BOOL bRedraw);//是否重画滚动条


例子：参考SetScrollInfo函数的例子。


第一百一十九个SetScrollInfo设置滚动条信息


函数定义：int SetScrollInfo（HWND hWnd;//滚动条所在的窗口句柄


int fnBar,//滚动条类型，SB_VERT垂直滚动条，SB_HORZ水平滚动条


LPSCROLLINFO lpsi,//滚动条各项信息结构体，后面会有介绍


BOOL fRedraw）;//指明是否重画滚动条


SetScrollInfo函数的第三个参数是一个SCROLLINFO结构体指针，关于该结构体的解释如下：


typedef struct tagSCROLLINFO
{
	UINT cbSize;//指明SCROLLINFO结构体大小，赋值sizeof(SCROLLINFO)
	UINT fMask;//指明nMin-nMax、nPage、nPos哪些成员有效,分别对应SIF_RANGE、SIF_PAGE、SIF_POS。


	//为SIF_DISABLENOSCROLL表明禁用滚动条。
	int nMin;//滚动条范围最小值
	int nMax;//滚动条范围最大值
	UINT nPage;//页大小（跟滚动条大小相关联）
	int nPos;//滚动条位置
	int nTrackPos;//这个成员在GetScrollInfo函数中有用。用于接收滚动条位置
} SCROLLINFO, FAR *LPSCROLLINFO;


这里要说明的是，为了避免不必要的麻烦，滚动条大小，滚动条范围必须和可见窗口以及实际窗口（视图？）大小一致。


也就是说当你可见窗口大小是300的时候，那么滚动条页大小也必须是300。如果实际窗口大小是2000的时候，那么滚动条范围就是0~1999，分别是最小值和最大值。而滚动条可移动范围也就是位置是在0~1700，因为当滚动条位置是0的时候，显示窗口是0 - 300，而位置是1700的时候刚好显示完窗口也就是1700~2000。滚动条位置是以滚动条上边为准。


要想让一个窗口具有滚动条风格，在调用CreateWindow函数时在第三个参数里指明就行了，在CreateWindow函数里也解释过，WS_VSCROLL指明窗口具有垂直滚动条风格，而WS_HSCROLL是水平滚动条。


关于滚动条消息的解释（WM_VSCROLL垂直，WM_HSCROLL水平）


下面的消息码存存于wParam参数里：


SB_LINEUP 滚动条上面的箭头按钮被单击了一下，水平滚动条对应的是左边的按钮


SB_LINEDOWN 滚动条下面的箭头按钮被单击了下，水平滚动条对应的是右边的按钮


SB_PAGEUP 滚动条滑柄与上面箭头按钮之间的区域被单击了一下，水平滚动条是左边之间


SB_PAGEDOWN 滚动条滑柄与下面箭头按钮之间的区域被单击了一下，水平滚动条是右边之间。


SB_ENDSCROLL 鼠标离开了滚动条。


SB_THUMBTRACK 滚动条滑柄被拉动


SB_THUMBPOSITION 滚动条滑柄被拉完后，鼠标左键抬起时。


例子：垂直滚动条窗口应用


水平滚动条的使用方法，跟这个大同小异，所以就不加放进来了，徒增负担，这里面使用了一个最关键的函数SetWindowOrgEx，映射窗口原点，时时根据滚动条位置设置对应的窗口原点。以保证当前显示窗口正确的部分。每次有滚动信息产生的时候，都重画了窗口，这个方法很原始。以后讲到ScrollWIndow函数时会有改进的，还有本例部分参考了


Programing Windows with MFC里面的内容，只不过那里面是用类来实现的，而我这个是完全是用API来实现的，包括创建窗口，消息处理。


好吧，新建一个WIN32 工程，下面是代码：


#include<windows.h>
#include<stdio.h>
#define LINESIZE 8
int nVScrollPos = 0, nVPageSize, nViewHeight = 2000;
LRESULT CALLBACK WinSunProc(HWND wnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wndcls;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_CROSS);
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR);
	wndcls.hInstance = hInstance;
	wndcls.lpfnWndProc = WinSunProc;
	wndcls.lpszClassName = "windowclass";
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls);
	HWND wnd;
	wnd = CreateWindow("windowclass", "first windows",
		WS_OVERLAPPEDWINDOW^WS_SIZEBOX^WS_MAXIMIZEBOX | WS_VSCROLL, 300, 200, 600, 400,
		NULL, NULL, hInstance, NULL);
	RECT rect;
	GetClientRect(wnd, &rect);
	nVPageSize = rect.bottom;//可见窗口高度
	SCROLLINFO si;
	si.cbSize = sizeof(SCROLLINFO);
	si.nMin = 0;
	si.nMax = 1999;//窗口实际大小是2000
	si.nPage = nVPageSize;//可见窗口高度和页大小设置一致
	si.nPos = 0;
	si.fMask = SIF_ALL;
	::SetScrollInfo(wnd, SB_VERT, &si, FALSE);//设置滚动条信息
	ShowWindow(wnd, SW_SHOWNORMAL);
	UpdateWindow(wnd);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
};
LRESULT CALLBACK WinSunProc(HWND wnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{


	char str[20];
	PAINTSTRUCT ps;
	HDC hdc;
	int y, nDelta;
	int nScrollPos, nMaxPos;
	switch (uMsg)
	{


	case WM_VSCROLL:
	{
		switch (LOWORD(wParam))//wParam的低二字节存储有滚动条消息码。
		{
		case SB_LINEUP:
			nDelta = -LINESIZE;//负数是向上滚动 LINESIZE 是滚动大小8
			break;
		case SB_PAGEUP:
			nDelta = -nVPageSize;//滚动一页，也就是可见窗口高度
			break;
		case SB_THUMBTRACK:
			//wParam的高二字节储存有滚动条的位置
			nDelta = (short int)HIWORD(wParam) - nVScrollPos;
			break;
		case SB_PAGEDOWN:
			nDelta = nVPageSize;
			break;
		case SB_LINEDOWN:
			nDelta = LINESIZE;
			break;
		default:
			return 0;
		}
	}
	//计算新位置
	//有这样一种情况，当滚动位置是5时，再向上滚动8个点，那是不可能的，所以要计算。
	nScrollPos = nVScrollPos + nDelta;
	nMaxPos = nViewHeight - nVPageSize;
	if (nScrollPos < 0)
		nDelta = -nVScrollPos;
	else if (nScrollPos > nMaxPos)
		nDelta = nMaxPos - nVScrollPos;
	if (nDelta != 0)
	{
		nVScrollPos += nDelta;
		SetScrollPos(wnd, SB_VERT, nVScrollPos, TRUE);//设置新位置
		::InvalidateRect(wnd, NULL, TRUE);//刷新窗口
	}
	return 0;
	case WM_PAINT:
		hdc = BeginPaint(wnd, &ps);
		::SetWindowOrgEx(hdc, 0, nVScrollPos, NULL);
		for (y = 0; y < 2000; y += 20)
		{
			MoveToEx(hdc, 0, y, NULL);
			LineTo(hdc, 600, y);
			sprintf(str, "%d:", y);
			TextOut(hdc, 0, y + 2, str, strlen(str));
		}
		return 0;
	case WM_CLOSE: ::DestroyWindow(wnd); return 0;
	case WM_DESTROY: PostQuitMessage(0); return 0;
	}


	return DefWindowProc(wnd, uMsg, wParam, lParam);
}


运行效果：





http://hi.baidu.com/3582077/item/1546021772fbdadebf90423e


第一百二十个SQLConnect连接数据源（ODBC API）


创建数据源有两种方法，一种用数据源ODBC管理器创建，一种用函数SQLConfigDataSource创建，先来说一下ODBC管理器创建，了解一些概念，首先用Access创建一个数据库（mdb文件），然后打开ODBC管理器，选择开始->设置->控制面板->管理工具->数据源（ODBC）。


程序窗口如下：


点“添加”按钮，添加一个数据源，到时候就可以用SQLConnect连接你所创建的数据源了。点“添加”按钮，弹出的窗口如下：




因为要连接的数据库文件是Access创建的，所以驱动程序选择MisrosoftAccess Driver(*.mdb), 点完成


(如果连接的是Sql server数据库，驱动程序选择“SQL Server")。


	。给数据源取一个名称，描述信息，如下：




	记住数据源的名称，SQLConnect函数的第二个参数填的就是数据源名称。填完上面信息后，点击“选择”按钮，选择数据库文件。如下图：




	一路点确定，完成，就可以了，创建了数据源我们就用SQLConnect函数来连接它吧。


	SQLConnect函数定义：


	SQLRETURN SQL_API SQLConnect(SQLHDBC ConnectionHandle,//数据源连接需要的连接变量,可用SQLAllocEnv创建
		SQLCHAR *ServerName, //数据源名称


		SQLSMALLINT NameLength1,//ServerName参数的长度，取SQL_NTS就行了。
		SQLCHAR *UserName, //用户名，没有为NULL


		SQLSMALLINT NameLength2,//用户名字符串长度，可取SQL_NTS。没有为0
		SQLCHAR *Authentication, //用户密码


		SQLSMALLINT NameLength3);//用户密码字符串长度


连接数据源的例子：


#include<windows.h>
#include<sqlext.h>//SQLConnect函数头文件
#include<iostream.h>
int main()
{
	HENV henv;//数据据源连接需要的环境变量
	HDBC hdbc;//数据源连接需要的连接变量
	RETCODE rcode;
	//创建环境句柄
	SQLAllocEnv(&henv);
	//创建连接句柄
	SQLAllocConnect(henv, &hdbc);
	//上面的语句是固定的，记住就行了。
	//连接数据源
	rcode = ::SQLConnect(hdbc, (PUCHAR)"MyODBC", SQL_NTS, NULL, 0, NULL, 0);
	if (rcode == SQL_SUCCESS)
	{
		cout << "连接数据源成功!" << endl;
	}
	else
	{
		cout << "连接失败!" << endl;
	}


	return 0;
}


连接数据库，也并非得通过连接数据源的方法实现，像SQLDriverConnect函数不使用 ODBC 数据源进行连接的，以后会介绍这个函数。


第二百二十一个SQLExecDirect执行SQL语句(ODBC API)


函数定义：


SQLRETURN SQL_API SQLExecDirect(SQLHSTMT StatementHandle,//语句句柄,SQLAllocStmt函数可分配
	SQLCHAR *StatementText,//SQL语句


	SQLINTEGER TextLength);//SQL语句字符串长度，可为SQL_NTS


一个执行SQL语句的例子：


#include<windows.h>
#include<sqlext.h>//SQLConnect函数头文件
#include<iostream.h>
int main()
{
	HENV henv;//数据据源连接需要的环境变量
	HDBC hdbc;//数据源连接需要的连接变量
	HSTMT hstmt;//语句变量
	RETCODE rcode;
	//创建环境句柄
	SQLAllocEnv(&henv);
	//创建连接句柄
	SQLAllocConnect(henv, &hdbc);
	//上面的语句是固定的，记住就行了。
	//连接数据源
	rcode = ::SQLConnect(hdbc, (PUCHAR)"MyODBC", SQL_NTS, NULL, 0, NULL, 0);
	if (rcode == SQL_SUCCESS)
	{
		cout << "连接数据源成功!" << endl;
	}
	else
	{
		cout << "连接失败!" << endl;
		return 0;
	}


	//分配句柄


	::SQLAllocStmt(hdbc, &hstmt);
	LPSTR pszSQL = new char[52];
	//假设数据库里表名为BookInfo,里面有BookPrice和BookName列。
	strcpy(pszSQL, "Update BookInfo set BookPrice=1000 whereBookName='VC++'");
	//执行SQL语句
	rcode = ::SQLExecDirect(hstmt, (UCHAR *)pszSQL, SQL_NTS);
	if (rcode == SQL_SUCCESS)
	{
		cout << "执行SQL语句成功!" << endl;
	}
	else
	{
		cout << "执行失败!" << endl;
	}
	::SQLDisconnect(hdbc);//解除连接
	return 0;
}


第一百二十二个SQLConfigDataSource配置数据源


函数定义：


BOOL SQLConfigDataSource(
	HWND hwndParent,//创建数据源的父窗口句柄，为NULL不显示创建数据源对话框。
	WORD fRequest,//指明对数据源进行什么操作，创建、修改、删除等。
	LPCSTR lpszDriver,//驱动程序名，对应上面创建新数据源对话框里的驱动程序名称。
	LPCSTR lpszAttributes);//此字符串以双'\0'结尾，包含数据各项属性，如用户ID，数据库文件路径，数据源名称等,项属性以'\0'间隔


fRequest参数的可选值信息如下：


ODBC_ADD_DSN：创建数据源；


ODBC_CONFIG_DSN：配置或者修改已经存在的数据源；


ODBC_REMOVE_DSN：删除已经存在的数据源；


//删除数据源的代码：


SQLConfigDataSource(NULL, ODBC_REMOVE_DSN, "MicrosoftAccess Driver (*.mdb)", "DSN=MyODBC\0\0");


ODBC_ADD_SYS_DSN：创建系统数据源；


ODBC_CONFIG_SYS_DSN：配置或者修改已经存在的系统数据源；


ODBC_REMOVE_SYS_DSN：删除已经存在的系统数据源；


ODBC_REMOVE_DEFAULT_DSN：删除缺省的数据源。


lpszAttributes参数，各属性名如下：


DSN：数据源的名称


DBQ：数据库路径


DEFAULTDIR：数据库缺省路径，也就是DBQ只填一个文件名，那么系统要到哪个目录去找这个文件


DESCRIPTION：说明，可随便赋值，就是上面的那个“Thisis my ODBC"


SERVER：服务器名称(SQL Server)


DATABASE：数据库名称，如master, model


一个创建数据源的例子：


#include<windows.h>
#include<sqlext.h>//SQLConnect函数头文件
#include<iostream.h>
#include <odbcinst.h>//SQLConfigDataSource函数头文件
int main()
{
	BOOL Result;
	Result = SQLConfigDataSource(NULL, ODBC_ADD_DSN, "Microsoft Access Driver(*.mdb)",
		"DSN=DsAccess\0DBQ=d:\\book.mdb\0\0");
	if (Result == TRUE)
	{
		cout << "数据源创建成功!" << endl;
	}
	else
	{
		cout << "创建失败!" << endl;
	}


	return 0;


}
可以到ODBC 数据源管理器去查看，看看有没有DsAccess这个数据源当然上面也有提示了。。。。


再举一个例子，SQL Server的：


先在SQL Server里创建一个数据库，名为MyDatabase，在其下新建一个表BookInfo, 字段BookName, BookPrice, 跟上面的Access表一样，创建好后，添加一行数据吧，BookName：VC++，BookPrice：87，关闭，保存。


然后添加Sql Server数据源，这里给出关键几步的截图。


数据源名称，服务器名如下：




服务器名是20110304 - 1717，这个根据自己的SqlServer服务器名来填。看下面，Sql Server截图。


知道是什么了吧。。那么用SQLConfigDataSource创建数据源的时候，最后一个参数的SERVER项填的就是这个名称。


上面有两个选项，第一项不需要用户填用户ID和密码，就可以登陆，使用默认。这里我选择第二个，那么我在调用SQLConnect连接数据源时候，就要填入ID和密码，而选择第一项的话，则不需要。


更改默认的数据库为MyDatabase，这个对应SQLConfigDataSource函数最后一个参数的DATABASE


之后，设置保持默认不变，一直点下一步，然后测试一下数据，点完成。。就可以了。。创建好了数据源，我们就用代码来测试一下。


如下：


#include<windows.h>
#include<sqlext.h>//SQLConnect函数头文件
#include<iostream.h>
#include <odbcinst.h>//SQLConfigDataSource函数头文件
int main()
{
	/*
	//这个是使用SQLConfigDataSource函数创建SQLServer数据源的代码
	BOOL Result;
	Result=SQLConfigDataSource(NULL,ODBC_ADD_DSN,"SQL Server",
	"DSN=MySqlServer\0SERVER=20110304-1717\0DATABASE=MyDatabase\0\0");
	if(Result==TRUE)
	{
	cout<<"数据源创建成功!"<<endl;
	}
	else
	{
	cout<<"创建失败!"<<endl;
	}*/




	/*
	HENV henv;//数据据源连接需要的环境变量
	HDBC hdbc;//数据源连接需要的连接变量
	HSTMT hstmt;//语句变量
	RETCODE rcode;
	//创建环境句柄
	SQLAllocEnv(&henv);


	//创建连接句柄
	SQLAllocConnect(henv, &hdbc);


	//如果配置数据源的时候，指定了使用用户输入ID和密码方式验证，那么连接的时候，
	//也必需提供正确的密码，反之则不需要
	rcode = ::SQLConnect(hdbc, (PUCHAR)"MySqlServer", SQL_NTS, (PUCHAR)"sa", SQL_NTS,
		(PUCHAR)"123456", SQL_NTS);
	if (rcode == SQL_SUCCESS || rcode == SQL_SUCCESS_WITH_INFO)
	{
		cout << "连接数据源成功!" << endl;
	}
	else
	{
		cout << "连接失败!" << endl;
	}


	::SQLAllocStmt(hdbc, &hstmt);
	LPSTR pszSQL = new char[52];
	//假设数据库里表名为BookInfo,里面有BookPrice和BookName列。
	strcpy(pszSQL, "Update BookInfo set BookPrice=1000 whereBookName='VC++'");
	//执行SQL语句
	rcode = ::SQLExecDirect(hstmt, (UCHAR *)pszSQL, SQL_NTS);
	if (rcode == SQL_SUCCESS)
	{
		cout << "执行SQL语句成功!" << endl;
	}
	else
	{
		cout << "执行失败!" << endl;
	}
	::SQLDisconnect(hdbc);//解除连接
	return 0;
}


第一百二十三个SQLDescribeCol获取结果集一列的信息，如列名，列的数据类型等


在接触SQLDescribeCol之前先提一个函数：SQLNumResultCols，这个函数获取结果集列的个数（就是一张表有几列）


这个函数只有两个参数，最后一个参数存储列数。


SQLDescribeCol函数定义：


SQLRETURN SQLDescribeCol(
	SQLHSTMT StatementHandle,//htstmt句柄
	SQLUSMALLINT ColumnNumber,//列索引，获取哪一列的信息，从1开始
	SQLCHAR * ColumnName,//存储列名
	SQLSMALLINT BufferLength,//参数ColumnName的大小（指向的内存）以字节为单位
	SQLSMALLINT * NameLengthPtr,//存储列名实际获得的长度
	SQLSMALLINT * DataTypePtr,//列的数据类型，如SQL_CHAR，SQL_FLOAT
	SQLULEN * ColumnSizePtr,//数据的长度，数据所占的字节，如int型默认4，char(10)，就是10
	SQLSMALLINT * DecimalDigitsPtr,//小数点位数
	SQLSMALLINT * NullablePtr);//列属性，数据是否可以为空，SQL_NO_NULLS列不允许空值，SQL_NULLABLE可以为空
例子：获取一张表里的所有列名。假设有一张Student表


#include<windows.h>
#include<sqlext.h>//SQLConnect函数头文件
#include<iostream.h>
#include <odbcinst.h>//SQLConfigDataSource函数头文件
int main()
{


	HENV henv;//数据据源连接需要的环境变量
	HDBC hdbc;//数据源连接需要的连接变量
	HSTMT hstmt;//语句变量
	RETCODE rcode;
	//创建环境句柄
	SQLAllocEnv(&henv);


	//创建连接句柄
	SQLAllocConnect(henv, &hdbc);
	rcode = ::SQLConnect(hdbc, (PUCHAR)"MySqlServer", SQL_NTS, NULL, 0,
		NULL, 0);
	if (rcode == SQL_SUCCESS || rcode == SQL_SUCCESS_WITH_INFO)
	{
		cout << "连接数据源成功!" << endl;
	}
	else
	{
		cout << "连接失败!" << endl;
	}


	::SQLAllocStmt(hdbc, &hstmt);
	LPSTR pszSQL = new char[52];
	//假设数据库里表名为Student
	strcpy(pszSQL, "Select * from Student");
	//执行SQL语句
	rcode = ::SQLExecDirect(hstmt, (UCHAR *)pszSQL, SQL_NTS);
	if (rcode == SQL_SUCCESS)
	{
		cout << "执行SQL语句成功!" << endl;
		short ColumnCount;//列数
		SQLNumResultCols(hstmt, &ColumnCount);
		cout << "列数:" << ColumnCount << endl;
		LPSTR pszName = new char[256];//列名
		UWORD ColumnIndex;//列的索引
		short BufferLength;//列名的长度
		SWORD ColumnType;//列的数据类型
		UDWORD ColumnSize;//数据的长度
		SWORD DecimalDigits;//小数点位数
		SWORD Nullable;//值是否可以为NULL
		cout << "列名:" << endl;
		//读取每一列的信息，从索引1开始
		for (ColumnIndex = 1; ColumnIndex <= ColumnCount; ColumnIndex++)
		{
			SQLDescribeCol(hstmt, ColumnIndex, (UCHAR *)pszName, 256, &BufferLength,
				&ColumnType, &ColumnSize, &DecimalDigits, &Nullable);
			//输出列名
			cout << pszName << " ";
		}
		cout << endl;


	}
	else
	{
		cout << "执行失败!" << endl;
	}
	::SQLDisconnect(hdbc);//解除连接
	return 0;
}


运行效果如下图：


第一百二十四个SQLBindCol绑定变量到一个列


绑定变量到一个列，就可以获得对应列任何一行的内容，比如StuName列，我定义一个字符串指针变量pName，并分配内存，把pName跟


StuName列绑定后，调用SQLFetch函数，就可以获得StuName列一行内容，默认是第一行，也就是第一行StuName列的数据，再次调用SQLFetch的话，pName存储的就是第二行StuName列的内容，依次递增。
SQLBindCol函数定义：


SQLRETURN SQLBindCol(
	SQLHSTMT StatementHandle,//hstmt句柄
	SQLUSMALLINT ColumnNumber,//获取哪一列的内容，列索引
	SQLSMALLINT TargetType,//数据类型
	SQLPOINTER TargetValuePtr,//绑定的变量
	SQLLEN BufferLength,//存储数据缓存区大小，也就是TargetValuePtr的大小
	SQLLEN * StrLen_or_Ind);//实际获取数据大小（相对于BufferLength）。每次绑定变量的数据改变，这个参数值也跟着改变，指明数据大小


这里得说一下第三个参数TargetType数据类型，这个参数对应SQLDescribeCol函数第六个参数DataTypePtr，它们的解释是一样的。


另外，即使函数填的数据类型和列实际类型不匹配，也可以，可以自动转换，当然这里有一个前提，它们得可以转换，比如字符串"12345"转换成整型12345是没有问题的，但字符串"1abc"显然不可以转换成整型。不过，读取的时候，不想去了解这其中关系的，数据类型填SQL_C_CHAR就行了，也就是SQL_CHAR，这个表示字符串。


试想，不管是整型，浮点型，还是日期类型都可以以字符串的形式来显示。而且你也可以调用相关的函数来转化类型，用这个就可以了。


如果愿望花时间去了解数据类型的区别，可以到MSDN去查，地址：（看那张表就行了）


http ://msdn.microsoft.com/en-us/library/ms714556(v=VS.85).aspx


例子：读取第一列，和第二列所有行数据。


#include<windows.h>
#include<sqlext.h>//SQLConnect函数头文件
#include<iostream.h>
#include <odbcinst.h>//SQLConfigDataSource函数头文件
int main()
{


	HENV henv;//数据据源连接需要的环境变量
	HDBC hdbc;//数据源连接需要的连接变量
	HSTMT hstmt;//语句变量
	RETCODE rcode;
	//创建环境句柄
	SQLAllocEnv(&henv);


	//创建连接句柄
	SQLAllocConnect(henv, &hdbc);
	rcode = ::SQLConnect(hdbc, (PUCHAR)"MySqlServer", SQL_NTS, NULL, 0,
		NULL, 0);
	if (rcode == SQL_SUCCESS || rcode == SQL_SUCCESS_WITH_INFO)
	{
		cout << "连接数据源成功!" << endl;
	}
	else
	{
		cout << "连接失败!" << endl;
	}


	::SQLAllocStmt(hdbc, &hstmt);
	LPSTR pszSQL = new char[52];
	//假设数据库里表名为Student
	strcpy(pszSQL, "Select * from Student");
	//执行SQL语句
	rcode = ::SQLExecDirect(hstmt, (UCHAR *)pszSQL, SQL_NTS);
	if (rcode == SQL_SUCCESS)
	{
		cout << "执行SQL语句成功!" << endl;
		short ColumnCount;//列数
		SQLNumResultCols(hstmt, &ColumnCount);
		cout << "列数:" << ColumnCount << endl;
		LPSTR pszName = new char[256];//列名
		UWORD ColumnIndex;//列的索引
		short BufferLength;//列名的长度
		SWORD ColumnType;//列的数据类型
		UDWORD ColumnSize;//数据的长度
		SWORD DecimalDigits;//小数点位数
		SWORD Nullable;//值是否可以为NULL
		cout << "列名:" << endl;
		//读取每一列的信息，从索引1开始
		for (ColumnIndex = 1; ColumnIndex <= ColumnCount; ColumnIndex++)
		{
			SQLDescribeCol(hstmt, ColumnIndex, (UCHAR *)pszName, 256, &BufferLength,
				&ColumnType, &ColumnSize, &DecimalDigits, &Nullable);
			//输出列名
			cout << pszName << " ";
		}
		cout << endl;
		char *pStuNo = new char[256];//绑定的变量,学号
		char *pStuName = new char[256];//绑定的变量,学生姓名
		long StuNolen;//实际获取数据的大小
		long StuNamelen;
		//绑定变量
		SQLBindCol(hstmt, 1, SQL_C_CHAR, pStuNo, 256, &StuNolen);//第一列
		SQLBindCol(hstmt, 2, SQL_C_CHAR, pStuName, 256, &StuNamelen);//第二列
		rcode = SQLFetch(hstmt);//获取内容
		while (rcode == SQL_ROW_SUCCESS || rcode == SQL_ROW_SUCCESS_WITH_INFO)
		{
			cout << pStuNo << " " << pStuName << endl;
			rcode = SQLFetch(hstmt);//获取下一行内容
		}
		SQLCancel(hstmt);
	}
	else
	{
		cout << "执行失败!" << endl;
	}


	::SQLDisconnect(hdbc);//解除连接
	return 0;
}


运行效果截图：





http://hi.baidu.com/3582077/item/08b15d260bc4bf3194f62b21


第一百二十五个SQLDriverConnect连接数据库
函数定义：
SQLRETURN SQLDriverConnect(
	SQLHDBC ConnectionHandle,//hdbc句柄
	SQLHWND WindowHandle,//窗口句柄，不显示窗口为NULL
	SQLCHAR * InConnectionString,//连接字符串，参照SQLConfigDataSource函数的最后一个参数
	SQLSMALLINT StringLength1,//InConnectionString缓存区大小
	SQLCHAR * OutConnectionString,//该参数接收连接详细信息。
	SQLSMALLINT BufferLength,//OutConnectionString缓存区大小
	SQLSMALLINT * StringLength2Ptr,//OutConnectionString实际大小（接收后）
	SQLUSMALLINT DriverCompletion);//是否显示连接窗口，SQL_DRIVER_NOPROMPT不显示。


SQLDriverConnect相比SQLConnect函数，功能强大许多，它可以直接连接数据库驱动，不需要通过数据源，当然它也可以连接数据源，SQLDriverConnect完全可以替代SQLConnect函数。


那么连接数据源的时候，如果需要ID和密码，这些信息填在哪里呢，填在InConnectionString连接字符串里。对应的项属性是


UID和PWD。这个参数的解释可以参考SQLConfigDataSource函数的最后一个参数。


SQLDriverConnect函数的InConnectionString多了几个项属性(较之SQLConfigDataSource函数的最后一个参数），前面UID和PWD算两个。还有一个是DRIVER，这个指明驱动名称。


	SQLDriverConnect应用例子：


#include<windows.h>
#include<sqlext.h>//SQLConnect函数头文件
#include<iostream.h>
#include <odbcinst.h>//SQLConfigDataSource函数头文件
	int main()
{


	HENV henv;//数据据源连接需要的环境变量
	HDBC hdbc;//数据源连接需要的连接变量


	RETCODE rcode;
	//连接数据源,项属性用分号隔开，不需要帐号密码验证的话，仅填数据源就行了
	SQLCHAR ConnStr[256] = { "DSN=MySqlServer;UID=sa;PWD=123456" };


	//直接连接Access数据库
	//SQLCHAR ConnStr[256]={"DBQ=d:\\book.mdb;DRIVER=Microsoft Access Driver(*.mdb)"};


	//直接连接SQL Server
	//SQLCHARConnStr[256]={"SERVER=20110304-1717;DATABASE=MyDatabase;DRIVER=SQLServer"};
	SQLCHAR OutConnStr[256];
	short OutConnStrLen;
	//创建环境句柄
	SQLAllocEnv(&henv);
	HWND desktopHandle = GetDesktopWindow();
	//创建连接句柄
	SQLAllocConnect(henv, &hdbc);
	rcode = ::SQLDriverConnect(hdbc, NULL, ConnStr,
		SQL_NTS,
		OutConnStr, 256, &OutConnStrLen, SQL_DRIVER_NOPROMPT);
	if (rcode == SQL_SUCCESS || rcode == SQL_SUCCESS_WITH_INFO)
	{
		cout << "连接成功!" << endl;
		cout << OutConnStr << '\t' << OutConnStrLen << endl;
	}
	else
	{
		cout << "连接失败!" << endl;
	}


	::SQLDisconnect(hdbc);//解除连接
	return 0;
}


第一百二十五个SQLFetchScroll滚动结果集行


前面提到的SQLFetch函数，只能向一个方向移动，就是当游标在第一行的时候，调用SQLFetch函数获得的是第二行的数据（关联的变量）。


而SQLFetchScroll不仅能向下一行移动，还能向上一行移动。也能获取特定行的数据。。


函数定义：SQLRETURN SQLFetchScroll(
	SQLHSTMT StatementHandle,//hstmt句柄
	SQLSMALLINT FetchOrientation,//标明，向前移动，还是向后移动。或者特定行。
	SQLLEN FetchOffset);//用于特定行，指明移动到哪行，也就获取哪行数据。向后或向前无意义，为0


第二个参数FetchOrientation有以下取值：


SQL_FETCH_NEXT//获取下一行


SQL_FETCH_PRIOR//获取上一行


SQL_FETCH_FIRST //获取首行


SQL_FETCH_LAST //获取最后一行


SQL_FETCH_ABSOLUTE //用于特指获取哪一行，FetchOffset指明行数


SQL_FETCH_RELATIVE //用于特指获取哪一行，位置为相对。如当前在第二行，FetchOffset为2，那么获取的是第4行。


如果直接调用SQLFetchScroll函数，会发现除了SQL_FETCH_PRIOR和SQL_FETCH_NEXT参数有效外，其它参数都无效，是什么原因呢。。是由于hstmt的属性造成的，默认属性规定游标只能向前移动。也就是SQL_CURSOR_FORWARD_ONLY。


（这里前一行，上行都给我搞乱了，FORWARD是向前的意思，NEXT是下一行的意思。。。没个统一的叫法，真搞不明白）


我们只要将HSTMT的SQL_ATTR_CURSOR_TYPE游标属性设置成静态的就行了。也就是SQL_CURSOR_STATIC。


用SQLSetStmtAttr函数可以设置。这个函数可以到MSDN里查。这里我只用它设置一下属性就行了，解决上面的问题。设置的语句哪下：


SQLSetStmtAttr(hstmt, SQL_ATTR_CURSOR_TYPE, (void*)SQL_CURSOR_STATIC, SQL_IS_INTEGER);


接着来一个简单例子，获取特定行的数据。


#include<windows.h>
#include<sqlext.h>//SQLConnect函数头文件
#include<iostream.h>
#include <odbcinst.h>//SQLConfigDataSource函数头文件
int main()
{


	HENV henv;//数据据源连接需要的环境变量
	HDBC hdbc;//数据源连接需要的连接变量
	HSTMT hstmt;//语句变量
	RETCODE rcode;
	//创建环境句柄
	SQLAllocEnv(&henv);


	//创建连接句柄
	SQLAllocConnect(henv, &hdbc);
	rcode = ::SQLConnect(hdbc, (PUCHAR)"MySqlServer", SQL_NTS, NULL, 0,
		NULL, 0);
	if (rcode == SQL_SUCCESS || rcode == SQL_SUCCESS_WITH_INFO)
	{
		cout << "连接数据源成功!" << endl;
	}
	else
	{
		cout << "连接失败!" << endl;
	}


	::SQLAllocStmt(hdbc, &hstmt);
	LPSTR pszSQL = new char[52];
	//假设数据库里表名为Student
	strcpy(pszSQL, "Select * from Student");
	//执行SQL语句
	//设置静态游标
	SQLSetStmtAttr(hstmt, SQL_ATTR_CURSOR_TYPE, (void *)SQL_CURSOR_STATIC, SQL_IS_INTEGER);
	rcode = ::SQLExecDirect(hstmt, (UCHAR *)pszSQL, SQL_NTS);
	if (rcode == SQL_SUCCESS)
	{
		cout << "执行SQL语句成功!" << endl;
		char *pStuNo = new char[256];//绑定的变量,学号
		long StuNolen;//实际获取数据的大小
		//绑定变量
		SQLBindCol(hstmt, 1, SQL_C_CHAR, pStuNo, 256, &StuNolen);//第一列
		//获取第二行的学号,学号最好按顺序排，如第一行001，第二行002，这样好查看结果的时候好区分的些。
		rcode = SQLFetchScroll(hstmt, SQL_FETCH_ABSOLUTE, 2);
		cout << pStuNo << endl;
		SQLCancel(hstmt);
	}
	else
	{
		cout << "执行失败!" << endl;
	}


	::SQLDisconnect(hdbc);//解除连接
	return 0;


}
*/ 