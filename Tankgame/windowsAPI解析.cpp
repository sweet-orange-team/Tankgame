/*

http://www.vbgood.com/api.html
http://hi.baidu.com/3582077/item/9cc3483b581f53c5392ffae3

��һ����FindWindow���ݴ��������򴰿ڱ���������ô��ڵľ�����ú������ش��ڵľ����
��������Ķ����������� HWND WINAPI FindWindow(LPCSTR lpClassName, LPCSTR lpWindowName); ��һ��������ڵ��������ڶ�����ڵı���������ʵ�ǲ���Ҫͬʱ�����������ģ�Ҳ����˵����ֻҪ֪�����ڵ������򴰿ڵı���Ϳ����ˣ�û�е��Ǹ�����NULL���档����������һ��������Ϊ"�ޱ���.txt - ���±�"�ļ��±�������ô�ҾͿ���������ĺ������������ڵľ�����ǻ����������ڵľ���ҿ��Ը�ʲô�أ����ÿɴ��ˣ���Ϊ�ܶ�������ڵĺ���������Ҫ���ھ�������������ƶ����ı䴰�ڴ�С��MoveWindow������������ٸ����ӣ���Ҿ͸�����ᵽ���FindWindow���÷����ô���

FindWindow���ӣ���֪һ���������ƣ�дһ������رոô��ڣ����赱ǰ��������һ��������Ϊ"�ޱ���.txt - ���±�"�ļ��±���������

#include<windows.h>//API������ͷ�ļ�
int main()
{
	HWND wnd;//����һ�����ھ�����������Դ洢�ҵ��Ĵ��ھ��
	wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");//��ô�����Ϊ"�ޱ���.txt - ���±�"�Ĵ��ھ��
	SendMessage(wnd, WM_CLOSE, 0, 0);//����SendMessage����������һ��WM_CLOSE���رգ���Ϣ��wnd���ھ����
	return 0;
}

���Ҫ���ݴ�����������ô��ھ������ֻҪ�������ĵ�һ���������������ڶ���������������NULL�����ɣ���Spy++�ɲ鿴����������

�ڶ�����SendMessage���ݴ��ھ������һ����Ϣ������
�������壺LRESULT SendMessage��HWND hWnd��UINT Msg��WPARAM wParam��LPARAM IParam����
��һ�������Ǵ��ھ�����ڶ�����������Ϣ���ͣ��������Ϣ���о���������Ϣ���������ĸ���������Ϣ������Ϣ��������������Ϣ���ͣ�����һ���ַ���Ϣ��WM_CHAR), ��ô�����������ʹ�����һ���ַ���ASCII�롣
��Ϣ���ƴ�Ҷ�Ӧ��֪���ɣ�Windows�ǻ�����Ϣ��ϵͳ������ƶ����̰������������Ϣ��
��������һ�����ӣ�����һ��WM_CHAR��Ϣ�����ڣ�Ҳ����ģ�¼��̰�����������Ϣ�Ĵ���������"�ޱ���.txt - ���±�"Ϊ����

SendMessage���ӣ�ģ�¼��̰���

#include<windows.h>
int main()
{
	HWND wnd;
	wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
	while (1)
	{
		SendMessage(wnd, WM_CHAR, WPARAM('a'), 0);
		Sleep(300);
	}
	return 0;
}
�Ǻ�����������ǲ���û�ã�����Ϊʲô�أ�����������𣿴���û�д�ֻ�Ǵ��ھ�������⣬��Ϣ���͸��������ڡ�������Ϣ�Ĵ��ڲ��ԡ����±����ڽ�����Щ��ʲô�����أ��˵����༭��״̬���ȿؼ����ؼ�Ҳ�Ǵ��ڣ���Ȼ�Ǵ��ڣ��ǵ�Ȼ����Ҳ�д��ھ�������ڼ��±�������������ֵģ��༭��ؼ�����ֵ��������ϢӦ�÷��ͱ༭��ؼ�������λ�ü��±���༭��ؼ��Ĵ��ھ���أ���FindWindow�𣿲�֪���༭�򴰿ڱ�����������Ҳ��֪������ȻҲ������������ȡ�༭�򴰿ڱ������ʹ�����������Spy++��������λ�ñ༭�����������Ժ�ĺ����л��н��ܣ��������Ǿ���WindowFromPoint�����������ȡ�����������ȡ���ھ���ķ����Ƚϱ���������������������˵������������Ǹ���ʲô����ȡ���ھ�����أ�������Ļ����㣬����Ļ�����20��20����ǰ���ĸ�����ռ�У��ͷ����ĸ����ڵľ��������������������ǻ���Ҫһ������GetCursorPos��ȡ��굱ǰλ�ã��������Ļ����
���е����ӣ�ģ�¼��̰�����
#include<windows.h>
int main()
{
	POINT curpos;//һ���ɴ��������Ľṹ�������x�����꣬y,�����꣬��curpos.x curpos.y
	while (1)
	{
		GetCursorPos(&curpos);//��ȡ��ǰ����λ�ã�λ�ý�������curpos�
		HWND hWnd = WindowFromPoint(curpos);//����curpos��ָ��������ȡ���ھ��
		SendMessage(hWnd, WM_CHAR, WPARAM('g'), 0);//����һ���ַ�����������Ϣg����ǰ�����ָ��Ĵ��ھ��
		Sleep(300);//˯�����ٺ��룬�൱�ڵȴ�����֮һ��
	}
}
�������һ���к�ֻҪ�����ָ��Ҫ�����ַ��Ĵ��ھ������ô���൱�ڼ���ÿ����֮һ�밴��һ��g�������԰ɣ�
�����������ģ�¼��̰���̫�鷳�Ļ�����ô����keybd_event������������ר������ģ�¼��̰����ģ�������ô�ã��Լ��ٶ�һ�ѣ���֪���ˡ���ȻSendMessage��ģ�¼��̰����Ļ�����Ҳ��ģ�����������һ�������ʱSendMessage�����������ĸ������Ľ��;��Ǵ��������������һ�ʱ��λ�á���ģ������һ�����һ�룬һ������һ����ļ������ֱ�������Ҽ����£�����Ҽ��ɿ�������㰴������Ҽ����ɿ��������ǲ�������һ������ǵģ�ֱ�����ɿ�����Ҽ�����������һ������������һ�.����Ҽ����µ���Ϣ�����ǡ�WM_RBUTTONDOWN�����Ҽ��ɿ�����Ϣ�ǡ�WM_RBUTTONUP������ôһ������������һ�Ӧ���ǣ�
SendMessage(wnd, WM_RBUTTONDOWN, 0, 0);//����Ҽ�����,�������ĸ�����˵������갴��ʱ��λ��
Sleep(100);//���100����
SendMessage(wnd, WM_RBUTTONUP, 0, 0);//����Ҽ��ɿ�
ͬ����Ҳ��һ��ר��ģ����궯���ĺ�����mouse_event�������������ģ�������ƶ���������˫���ȡ��Ժ����ר�Ž��ܡ�

��������GetCursorPos��ȡ��굱ǰλ�ã���Ļ��

���������SendMessage�����н��ܣ��������һ�����ӣ��ڽ����ﲻͣ�������굱ǰλ�á�
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


���ĸ���WindowFromPoint����������ö�Ӧ�Ĵ��ھ��
��SendMessage�н��ͣ��������һ�����ӣ����ָ���ĸ����ڣ��͹ر��ĸ����ڡ�
#include<windows.h>
int mai()
{
	Sleep(2500);//�ȴ�һ��������ڰ�����Ƶ�����������ȥ������ָ������̵Ĵ��ڣ��ص��Լ��Ĵ��ڡ�
	POINT curpos;
	while (1)
	{
		GetCursorPos(&curpos);
		HWND wnd = WindowFromPoint(curpos);
		SendMessage(wnd, WM_CLOSE, 0, 0);
		Sleep(300);

	}

}

�����MoveWindow���ݴ��ھ���ƶ����ڣ��ı䴰�ڴ�С
�������壺BOOL MoveWindow(HWND hWnd, int X, int Y, intnWidth, int nHeight, BOOL bRepaint);
hWnd��Ҫ�ı��С�Ĵ��ڵľ����x, y�������Ļ�����꣬�������Ͻǵ�λ����֮���Ӧ��nWidth��nHeight�Ǵ����µĿ�ߣ�bRepaintָ�������Ƿ��ػ���
����������"�ޱ���.txt - ���±�"Ϊ���ӣ��ı�������ڴ�С�����Ѵ����Ƶ����Ͻ�ȥ��
#include<windows.h>
int main()
{
	HWND wnd;
	wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
	MoveWindow(wnd, 0, 0, 220, 120, NULL);
	return 0;
}
������ShowWindow���ô�����ʾ״̬�������أ���󻯣���С��

��������BOOL ShowWinow(HWND hWnd, int nCmdShow);
SW_HIDE�����ش��ڲ������������ڡ���һ������hWndָ���˴��ھ�����ڶ�������ָ���˴��ڵ�״̬�����ڸ����ڶ�����������ȡֵ��Χ��
SW_MAXIMIZE�����ָ���Ĵ��ڡ�
SW_MINIMIZE����С��ָ���Ĵ��ڲ��Ҽ�����Z���е���һ�����㴰�ڡ�
SW_RESTORE�������ʾ���ڡ����������С������󻯣���ϵͳ�����ڻָ���ԭ���ĳߴ��λ�á��ڻָ���С������ʱ��Ӧ�ó���Ӧ��ָ�������־��
SW_SHOW���ڴ���ԭ����λ����ԭ���ĳߴ缤�����ʾ���ڡ�
ShowWindow���ӣ��������к�������������һ��ָ���Ĵ��ڣ�����4����ٽ�����ʾ
#include<windows.h>
int main()
{
	HWND wnd;
	wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
	ShowWindow(wnd, SW_HIDE);
	Sleep(5000);
	ShowWindow(wnd, SW_SHOW);
	return 0;
}


���߸�SetCursorPos��������λ�á�������ƶ���ָ����λ��
�������壺BOOL SetCursorPos(int x, int y);
�����������������������Ӧ��֪����ʲô��˼�ɣ���Ļ������㡣
ֱ�ӿ����ӣ�
#include<windows.h>
int main()
{
	int sec = 0;
	while (sec < 200)
	{
		SetCursorPos(rand() % 1024, rand() % 768);//�����������λ��
		Sleep(20);
		sec++;
	}
	return 0;
}

�ڰ˸�CopyFile����һ���ļ�

��θ���һ���ļ������磬��Ҫ��E�̵�abb.txt���ı��ļ����Ƶ�d�̵�zhengyong.txt, ��������
CopyFile("e:\\abb.txt", "d:\\zhengyong.txt", FALSE); ���ɡ�
����������������˵����
�����ΪTRUE�����㣩����ôһ��Ŀ���ļ��Ѿ����ڣ��������û�ʧ�ܡ�����Ŀ���ļ��ᱻ���ǵ���

�ھŸ�DeleteFileɾ��һ���ļ�
���ɾ��һ���ļ�����䣺DeleteFile("e\\abb.txt"); ����ɾ��
���Ŀ��Ϊ���ػ�ֻ���������á�
��ʮ��CreateDirectory����һ���ļ��У�Ŀ¼��
����E����ʲô�ļ�Ҳû��
CreateDirectory("e:\\aaa\\bbb", NULL); �����Ǵ�ģ�����ͬʱ�������ļ�������E�����Ѿ����˸�aaa�ļ����ˡ�
�����ǶԵ�CreateDirectory("e:\\aaa", NULL);
http://hi.baidu.com/3582077/item/f032b82bbbfb71c0ee10f1e3

��ʮһ����GetClientRect��ô��ڴ�С(�ͻ�����

	�����ӣ�
#include<windows.h>
#include<stdio.h>
	int main(int argc, char* argv[])
{
	HWND wnd;
	while (1)
	{
		wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
		RECT rect;//ר�������洢���ڴ�С
		GetClientRect(wnd, &rect);//��ȡ���ڴ�С
		printf("%d,%d,%d,%d\n", rect.left, rect.top, rect.right, rect.bottom);//������ڴ�С�����������ı䴰�ڴ�С
		Sleep(300);
	}
}

��ʮ������GetWindowRect��ô��ڴ�С�������Ļ��
���ӣ�
#include<windows.h>
#include<stdio.h>
int main(int argc, char* argv[])
{
	HWND wnd;
	while (1)
	{
		wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
		RECT rect;//ר�������洢���ڴ�С
		GetWindowRect(wnd, &rect);//��ȡ���ڴ�С
		printf("%d,%d,%d,%d\n", rect.left, rect.top, rect.right, rect.bottom);//������ڴ�С�����������ı䴰�ڴ�С
		Sleep(300);
	}
}

��ʮ����FindFirstFileѰ���ļ��Լ�����ļ�����Ϣ


�����һ�����Ӱɣ��о�E�̵�һĿ¼�µ������ļ��������ļ��У����FindNextFile


#include<windows.h>
#include<stdio.h>
int main()
{
	BOOL done = TRUE;
	WIN32_FIND_DATA fd;
	HANDLE hFind = FindFirstFile("e:\\*.*", &fd);//��һ��������·����������ʹ��ͨ�������DOS����Ӧ��֪���ɣ�fd�洢���ļ�����Ϣ
	while (done)
	{
		printf("%s\n", fd.cFileName);
		done = FindNextFile(hFind, &fd); //���ص�ֵ���Ϊ0��û���ļ�ҪѰ��
	}
	return 0;
}
��ȻҲ����ֱ����һ���ļ�����ʹ��ͨ�������������ʲô�����أ�����FindFirstFile("e:\\aaa.txt", &fd); ��ʵ������Ի�ȡһ���ļ�����Ϣ�����ļ��ǲ������صģ�������û��ֻ�����Եȡ�
��Ȼͨ������ͨ�����Ҳ����Ѱ���ض����͵��ļ���������ֻҪ���ı��ļ�����ô����������FindFirstFile("e:\\*.txt", &fd); �����ˣ��ؼ������Լ�������á�
ǰ��˵��fd��洢���ļ�����Ϣ������ô����fd����ĳ�Ա�ж�����ļ������ԣ��ļ��Ƿ����أ��ǲ����ļ��С�
fd���dwFileAttributes�洢���ļ�����Ϣ�����ж��Ƿ�Ϊ�ļ��У�ֻҪ�����������FILE_ATTRIBUTE_DIRECTORY���а�λ�����㣬�����Ϊ0�Ļ�������Ϊ�ļм�����if(fd.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) printf("%s���ļ���\n", fd.cFileName);
�����ж�Ҳ��һ�������ڸ����ļ�������(���ü�������FILE_ATTRIBUTE_HIDDEN�����أ�
	FILE_ATTRIBUTE_READONLY��ֻ����FILE_ATTRIBUTE_SYSTEM��ϵͳ��

	��ʮ�ĸ�FindNextFileѰ���ļ�
	����FindFirstFile����������!
	��ʮ���MoveFile�ƶ��ļ�
	���һ��������ı��Ƶ���һ������ȥ : MoveFile("e:\\a.txt", "d:\\abc.txt"); ���ɣ���˼��e���µ�a.txt�Ƶ�d����ȥ��������Ϊabc.txt
	������GetClassName���ݴ��ھ����ô�������
	�������壺int GetClassName(HWND hWnd, LPTSTR IpClassName, intnMaxCount)��
	���ֺ�������Ҫ�ٽ����˰ɣ�ǰ����̫�����Ƶ����ӡ�

	��ʮ�߸�SetFileAttributes�����ļ�����
	�������壺BOOL SetFileAttributes(LPCTSTRlpFileName, DWORDdwFileAttributes);
��������ĵڶ�������dwFileAttributes��ǰ�潲����WIN32_FIND_DATA�ṹ���dwFileAttributes��Ա���Ӧ������E�̵�һĿ¼����һ���ı��ļ�a.txt�������ļ�����Ҫ������Ϊֻ����������Ҫ������أ���ǰ����ܹ�WIN32_FIND_DATA�ṹ��dwFileAttributes��Ա�ļ����������ԣ������������֪��������FILE_ATTRIBUTE_HIDDEN��ֻ����FILE_ATTRIBUTE_READONLY��
��ô��E�����ı��ļ���������Ϊ���غ�ֻ���������ǣ�
SetFileAttributes("e:\\a.txt", FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY);
(�����������ͬ��Ҳ�������ļ������ԣ�
	��Ȼ��������ԴﵽҪ�󣬵��������ã���Ϊ�Ḳ�ǵ��ļ���ԭ�����ԣ�Ҳ����˵�������ļ�֮ǰ��ϵͳ���ԣ�ϵͳ�ļ����Ļ�����ô������һ��ִ�к��ļ���ֻ�����غ�ֻ�������ˡ�
	����һ���ļ�ԭ�Ⱦ����������ԣ�������a.txtΪ���ӣ���ô�Ұ�����Ϊֻ�����ǲ���������Ϳ����أ�


	SetFileAttributes("e:\\a.txt", FILE_ATTRIBUTE_READONLY��; �����Ļ�����Ȼ�ļ���ֻ�������ˣ�����������ȴû���ˡ�


		��Ҫ����ڲ����ǵ�ԭ���������£����ļ���Ϊֻ���أ���ʵ˵����ô��ķϻ����ܽ�������һ�仰���������һ���ļ������ԣ�


		ǰ����Ҫ�������ļ���ԭ�����ԣ�����ļ������ԣ���FindFirstFile�����������ðɣ�ֱ�ӿ����ӣ�


		����e�̵�a.txt�ļ�����Ϊ���أ���������ֻ�����ԣ�
#include<windows.h>
		int main()


{
	WIN32_FIND_DATA fd;
	FindFirstFile("e:\\a.txt", &fd);
	fd.dwFileAttributes |= FILE_ATTRIBUTE_READONLY;//��ԭ��������������ֻ������
	SetFileAttributes("e:\\a.txt", fd.dwFileAttributes);//�����ļ�������
	return 0;
}
�ڶ������ӣ����ȥ��һ���ļ�������


����ϰһ�£�������ֱ��������


���붮����İ�λ�򡢰�λ����߰�λ����������Ӧ��֪�������ȥ��һ���ļ������ԡ���ʵһ���ļ���Ϣ�����Զ�������˵���ġ�


����һ����λ�������룺10000010�������ÿһλ�ǲ���ֻ��0��1ȡֵ������0������1�����ÿ��Ա�ʾһ���ļ����Ե����ޣ�������ļ������ص���ֻ���ǺͲ��ǣ��������ǹ涨�����λ��������ĵ�һλ����ȷ���ļ��Ƿ�����������ԣ����Ϊ1�Ǳ������أ�����û�У��Դ����Ƶڶ�λ�ʹ����ļ���ֻ��������λϵͳ��������Ҫ����ж��أ����߰�ĳһλ��ֵ�ı��أ��ð�λ����Ϳ��ԣ�00000010����Ҫ�ѵ�2λ��ֵ��Ϊ0������λ�ϵ�ֵ���ֲ��䣬�ð�λ������㼴�ɣ���00000010���а�λ������㣬�����ﲢ������������������㣬�����κΰ�λ����������ֵ�Ƕ���ֻҪ��00000010���а�λ������㣬�ǵڶ�λ������0����������λ���ֲ��䡣����Ϊ�˷��㣬���ǾͰ�00000010���к궨�壬������䣬�������������ʮ����Ϊ2���궨��#define FILE_ATTRIBUTE_READONLY 2


������������Ǿ������һ���ļ���һ�����԰ɣ�


���һ���ļ����������ԣ�����a.txtΪ�����ļ���


#include<windows.h>
int main()


{
	WIN32_FIND_DATA fd;
	FindFirstFile("e:\\a.txt", &fd);//��ȡ�ļ���Ϣ
	fd.dwFileAttributes ^= FILE_ATTRIBUTE_HIDDEN;//��ԭ����������ɾ����������
	SetFileAttributes("e:\\a.txt", fd.dwFileAttributes);//�����ļ�������
	return 0;
}


�������ֻ����ļ������Խ��в����Ļ���������GetFileAttributes������ȡ�ļ������ԣ��ú���ֻһ���������Ǿ����ļ���·������������һ��DWORDֵ�������ļ�������Ϣ��


��ʮ�˸�ShellExecute����һ������
�������� : ShellExecute(HWND hwnd, LPCSTR lpOperation, LPCSTRlpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd);
��һ������hwnd�Ǹ����ڵľ��, ����ΪNULL, �ڶ�������lpOperation��ʾ��Ϊ, ����������lpFile�ǳ����·����, ���ĸ�����lpParameters�Ǹ����򿪳���Ĳ���, ����ΪNULL, ���������lpDirectory����ΪNULL, ����������nShowCmd��ShowWindow�����ĵڶ�������һ��, ����Ҳһ��, ����򿪵ĳ����д��ڵĻ�, ���������ָ���˴��������ʾ.
�����һ�����±�:
ShellExecute(NULL, "open", "NOTEPAD.EXE", NULL, NULL, SW_SHOWNORMAL);
�����������������ָ�������һ�����ڳ��������͵��ļ�, ����e����һ��a.txt�ļ�; �ҵ��ú������м��±����򲢴�����ı��ļ�.
ShellExecute(NULL, "open", "NOTEPAD.EXE", "e:\\a.txt", NULL, SW_SHOWNORMAL);
�������ڼ��±���������ϵͳ�����Դ��ĳ���, ����û�о���·��.
������������Դ�һ����վ:
ShellExecute(NULL, "open", "http://www.baidu.com", NULL, NULL, SW_SHOWNORMAL);
ShellExecute(NULL, "open", "C:", NULL, NULL, SW_SHOWNORMAL);


�����Ը����ļ���׺��ѡ����Ӧ�ĳ����һ���ļ���
ShellExecute(NULL, "open", "e:\\a.bmp", NULL, NULL, SW_SHOWNORMAL);
���Ƶĺ�������WinExec��ֻ����������, �������һ��������ShellExecute���������һ������һ��.
����һ���������ǳ���·����.�ٸ�����:WinExec("NOTEPAD.EXE", SW_SHOWNORMAL);
�������Ҳ���Ը����򴫵�һ���ļ�����Ҫ���еĳ����, ��Ҫ��μӽ�ȥ��, ������û�е���������,
������·��������NOTPEPAD.EXE�ĺ���, Ҫ�Կո����ֿ���:
WinExec("NOTEPAD.EXE e:\\a.txt", SW_SHOWNORMAL);


��ʮ�Ÿ�PlaySound����һ��WAV�ļ�


�������壺BOOL PlaySound(LPCSTR pszSound, HMODULE hmod, DWORDfdwSound);


��һ��������WAV�ļ���·�������ڶ�������������ǲ���MFC������ԴID�������ļ��������Ϊ�գ�������������ָ�����Ժ��ַ�ʽ�����ļ���ע���������ֻ�ܲ���100K���µ�WAV�ļ���


����E���и�a.wav�ļ�������������Ӳ�������ļ���


#include<windows.h>
#include<mmsystem.h>//PlaySound������ͷ�ļ�
#pragma comment(lib, "winmm.lib")//���ӿ⣬PlaySound��������ʹ��
int main()


{
	PlaySound("e:\\19.wav", NULL, SND_SYNC);
	return 0;
}


�ڶ�ʮ��GetModuleFileName����ģ�鵼����ȡ���������·��


�������壺DWORD GetModuleFileName(HMODULE hModule, LPTSTRlpFilename, DWORD nSize);


���ڵ�һ�������������Ժ�Ķ�̬���ӿ�����н��ܣ���������ֻҪ��ó������·������ô��һ����������Ϊ�ա�


�ڶ����������Դ洢·����nSizeָ���ַ������С��


����ٸ����ӣ����к󣬰���������ƶ���e���£�������Ϊa.exe;


#include<windows.h>


int main()


{


	char szAppName[128] = { 0 };
	GetModuleFileName(NULL, szAppName, 128);


	MoveFile(szAppName, "e:\\a.exe");


	return 0;


}





http://hi.baidu.com/3582077/item/fc3e11164b01c00dd0d66de5


�ڶ�ʮһ��CreateWindow����һ������


//��ϰ������ֱ������


֮ǰAPI���������ӣ��������DOS��̵ģ��ϸ���˵����windows�µķ�DOS��cmd)���б�̣���д����̨Ӧ�ó����Ҷ�֪������������main�������windows��̵�������Ҳ��main�𣿲��ǵģ�windows�µ�����������ں�������WinMain���ڶ���main��������ʱ�򣬿��Ը���������������Ҳ���Բ�������WinMain�����Ͳ��������ˣ����й̶��ĸ�ʽ����������ĸ�������


�ָ���WinMain�����Ĺ̶���ʽ��


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCEhPrevInstance, LPSTR lpCmdLine, int nCmdShow)


����������Ȥ����ͨ�����������˽�һ�¸���������˼����������ֻ��Ҫ֪��WinMain����������������ģ������Ҳû��ϵ��


֪����������Ǿ�����һ��WINDOWS����ɣ�


��Ϊ���������windows��̣�����Ҫ��һ��Win32Application���̣������ǵ���ļ���Ȼ��ѡ���½����ڵ����ĶԻ�����ѡ�񹤳̣���ѡ��Win32Application �������ұߵĹ���������������ƣ��������ȡ��֮���ȷ���������ֵ�����һ���Ի�������Ϊ�˷��㣬����ѡ��һ���򵥵� Win32 ���򡱣�����ɡ�����˫��WinMain��������༭���ڣ�����������ǾͿ��Դ�����ˡ�


�򵥵��������£�


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


��ô�����򵥰ɣ��ǲ��Ǿ�����֣���ôû�д��ڣ���Ϊ����Ҫ�Լ��������������̨����ֻҪһ���б���д��ڡ���Ȼû�д��ڣ����㴴����һ�����̣�������������������ҵ������������Ǹ����̣���ʵҲûʲô��ֵģ���WINDOWS�����һЩϵͳ����Ҳ��ֻ�н��̣�û�д��ڵ���spoolsv.exe, svchost.exe��


��Ҫ��δ���һ�������أ�Ҫ����һ������, �ͱ���Ҫ��ϵͳ�ṩ���ڵ���Ϣ������Ҫ�����Ĵ������ֽ�ʲô������ͼ����ʲô�����ڴ�С�����ڱ���ɫ�ȣ���Ȼ��ϵͳ��ô���㴴�������أ�����Ϊ�˷��㣬VC�Ͷ�����һ���ṹ��ר�����ڴ洢������Ϣ��


�ָ�������ṹ�Ķ��塣


typedef struct _WNDCLASS {
	UINT style; //��������
	WNDPROC lpfnWndProc; //���ڴ�����
	int cbClsExtra; //��ʾ������ṹ֮�����Ķ�����ֽ�����ϵͳ����ֵ��ʼ��Ϊ0
	int cbWndExtra; //��ʾ����ʵ��֮�����Ķ�����ֽ�����ϵͳ����ֵ��ʼ��Ϊ0
	HINSTANCE hInstance;// Ӧ�ó���ʵ�������WinMain���������� 
	HICON hIcon; //����ͼ���� 
	HCURSOR hCursor; //���ڹ����
	HBRUSH hbrBackground; //��ˢ���
	LPCTSTR lpszMenuName; //���ڲ˵���
	LPCTSTR lpszClassName; //��������
} WNDCLASS, *PWNDCLASS;


���ˣ���������Ѿ��Ѵ�����Ϣ����ˣ�������Ҫ�����������Ϣ����ϵͳ�أ�Ҳ���ǰ�Ҫ�������ڵ���Ϣ����ϵͳ���������ǵ���RegisterClass��������ʵ��������ܡ�ע���괰�ڣ����Ǿ�Ҫ��������, ��CreateWindow��������ʵ�֣���Ҫ��Ϊʲôע�ᴰ�ں�ֱ����ʾ�������ˣ���Ҫ��ʲô�������ڡ�����Ҳ��֪����������ֻҪ��ס���ʽ�����ˣ�Ӳʽ�涨�ģ����봴��һ�����ڣ��ͱ��밴��Щ��������


���ˣ����ڴ����ˣ����Ǿ�Ҫ����ShowWindow������ʾ���ڣ�Ȼ����UpdateWindow����ˢ��һ�£�ȷ��������������ʾ��


������ϸʵ�ִ��룺


#include "stdafx.h"
#include<windows.h>
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{


	WNDCLASS wndcls; //����һ���洢������ϢWNDCLASS����
	wndcls.cbClsExtra = 0; //Ĭ��Ϊ0
	wndcls.cbWndExtra = 0; //Ĭ��Ϊ0
	wndcls.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); //������ˢ
	wndcls.hCursor = LoadCursor(NULL, IDC_CROSS); //ʮ�ֹ��
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR); //����ͼ��
	wndcls.hInstance = hInstance; //Ӧ�ó���ʵ�������WinMain���������� 
	wndcls.lpfnWndProc = NULL; //������Ϣ������
	wndcls.lpszClassName = "windowclass"; //��������
	wndcls.lpszMenuName = NULL; //���ڲ˵�����û�в˵���ΪNULL
	wndcls.style = CS_HREDRAW | CS_VREDRAW;//�������ͣ�CS_HREDRAW��CS_VERDRAW ����
	//������ˮƽ����ֱ����Ŀ�ȱ仯ʱ�ػ���������
	RegisterClass(&wndcls); //�Ѵ�����Ϣ�ύ��ϵͳ��ע�ᴰ����
	HWND hwnd; //���Դ洢CreateWindow�����������Ĵ��ھ��
	hwnd = CreateWindow("windowclass", "first windows",
		WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);//��������
	ShowWindow(hwnd, SW_SHOWNORMAL);//���ڴ������ˣ���ʾ��
	UpdateWindow(hwnd); //���´��ڣ��ô��ں����ӳٵ���ʾ
	return 0;
}


�ǲ��ǳ����ˣ��ڴ治�ܶ�ȡ��Ϊʲô���أ���Ϊ�㴴���Ĵ���û����Ϣ��������windowsϵͳ��Ȼ����������һ�����ڴ��ڣ��԰�������궼û�з�Ӧ�������Ĵ�����û��ʵ������ġ� wndcls.lpfnWndProc = NULL; //������Ϣ������������ǰ����䣬����Ҫ��
���ڹ��̣���Ϣ�������������������������������أ���WinMainһ������Ҳ�й̶��ĸ�ʽ��


���ڹ��̴������ĸ�ʽ��LRESULT CALLBACK WinSunProc(HWND wnd, UINTuMsg, WPARAM wParam, LPARAM lParam)


����������һ�����ڴ������������ӣ�


#include "stdafx.h"
#include<windows.h>
LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_LBUTTONDOWN)MessageBox(NULL, "kdjfkdf", "Kjdfkdfj", MB_OK);//������갴����Ϣ��������Ϣ��
	return DefWindowProc(hwnd, uMsg, wParam, lParam); //δ�������Ϣͨ��DefWindowProc��������ϵͳ����
}
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{


	WNDCLASS wndcls; //����һ���洢������ϢWNDCLASS����
	wndcls.cbClsExtra = 0; //Ĭ��Ϊ0
	wndcls.cbWndExtra = 0; //Ĭ��Ϊ0
	wndcls.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); //������ˢ
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW); //���
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR); //����ͼ��
	wndcls.hInstance = hInstance; //Ӧ�ó���ʵ�������WinMain���������� 
	wndcls.lpfnWndProc = WinSunProc; //������Ϣ������
	wndcls.lpszClassName = "windowclass"; //��������
	wndcls.lpszMenuName = NULL; //���ڲ˵�����û�в˵���ΪNULL
	wndcls.style = CS_HREDRAW | CS_VREDRAW;//�������ͣ�CS_HREDRAW��CS_VERDRAW ����
	//������ˮƽ����ֱ����Ŀ�ȱ仯ʱ�ػ���������
	RegisterClass(&wndcls); //�Ѵ�����Ϣ�ύ��ϵͳ��ע�ᴰ����
	HWND hwnd; //���Դ洢CreateWindow�����������Ĵ��ھ��
	hwnd = CreateWindow("windowclass", "first windows",
		WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);//��������
	ShowWindow(hwnd, SW_SHOWNORMAL);//���ڴ������ˣ���ʾ��
	UpdateWindow(hwnd); //���´��ڣ��ô��ں����ӳٵ���ʾ
	MSG msg;//��Ϣ�ṹ����
	while (GetMessage(&msg, NULL, 0, 0))//��ȡ��Ϣ
	{
		//TranslateMessage(&msg); //�˺������ڰѼ�����Ϣ(WM_KEYDOWN,WM_KEYUP)ת�����ַ���ϢWM_CHAR
		DispatchMessage(&msg); //����������ô��ڹ��̴�����������MSG�����Ϣ����󴫸����̺������ĸ�����
	}
	return 0;
}


WinSunProc�������ĸ��������ֱ��Ӧ��SendMessage�����ĸ�����������μ�SendMessage�����������͡�


MSG���ͽ��� ��


�ṹ���壺


typedef struct tagMSG
{
	HWND hwnd;//hwnd��ʾ��Ϣ��Ҫ���͸��Ĵ��ھ��
	UINT message;//��Ϣ���ͣ���WM_WMCLOSE,WM_CHAR,WM_LBUTTONDOWN,�μ���Ϣ��
	WPARAM wParam;//��Ϣ������Ϣ��ȡֵ����˼����������Ϣ���Ͷ���
	LPARAM lParam;//��Ϣ������Ϣ��ȡֵ����˼����������Ϣ���Ͷ���
	DWORD time;//��Ϣ�ķ���ʱ�䣬������
	POINT pt;//��Ϣ����ʱ��������ڵ�λ�ã�������
}MSG;


������Ű��������������һ�飬Ȼ��ص����ڣ�������һ�飬�ǲ��ǳ����ˣ���Ϊǰһ��������Ȼ���ڹر��ˣ������̻������У����ǵ��Ǹ�ѭ�������while(GetMessage(&msg, NULL, 0, 0))���������ֻҪ�������������̾ͻ�һֱ������ȥ����������ѭ�������أ��� PostQuitMessage(0); ����������ˣ�����0��ʾ�������ڷ���һ���˳���Ϣ����GetMessage�����ӵ�PostQuitMessage������������Ϣ�󣬾ͻ᷵��0ֵ��


���ڴ��ڹ��̺����д����ڹر�WM_CLOSE��Ϣ : if (uMsg == WM_CLOSE��PostQuitMessage(0); ����ֻҪһ�رմ��ڣ����Ľ���Ҳ�������


	����������һ��CreateWindow������������˼, ��������


	HWND CreateWindow(LPCTSTR lpClassName,//����������Ӧ��WNDCLASS�ṹ��ĳ�ԱlpszClassNameһ��
		LPCTSTR lpWindowName, ,//���ڱ�����
		DWORD dwStyle��//���ڵķ��ȡֵ�μ���Style


		int x,
		int y,//x,y��ʾ�������������Ͻ�λ��
		int nWidth,
		int nHeight,//nWidth,nHeight��ʾ���ڵĿ��
		HWND hWndParent,//�����ھ������������Ӵ��ڣ�����ȡֵΪNULL
		HMENU hMenu,//�˵������û�˵��Ļ���ȡNULLֵ
		HANDLE hlnstance,//��Ӧ��WinMain�����ĵ�һ������
		LPVOID lpParam);//NULL


��Style�����ο����ٶȣ�


WS_BORDER������һ�����߿�Ĵ��ڡ�
WS_CAPTION������һ���б����Ĵ��ڣ�����WS_BODER��񣩡�
WS_CHILD������һ���Ӵ��ڡ�����������WS_POPUP�����á�
WS_CHLDWINDOW����WS_CHILD��ͬ��
WS_CLIPCHILDREN : ���ڸ������ڻ�ͼʱ���ų��Ӵ��������ڴ���������ʱʹ��������
	WS_CLlPBLINGS���ų��Ӵ���֮����������Ҳ���ǣ���һ���ض��Ĵ��ڽ��յ�WM_PAINT��Ϣʱ��WS_CLIPSIBLINGS ������в�������ų��ڻ�ͼ֮�⣬ֻ�ػ�ָ�����Ӵ��ڡ����δָ��WS_CLIPSIBLINGS��񣬲����Ӵ����ǲ���ģ������ػ��Ӵ��ڵĿͻ���ʱ���ͻ��ػ��ڽ����Ӵ��ڡ�
	WS_DISABLED : ����һ����ʼ״̬Ϊ��ֹ���Ӵ��ڡ�һ����ֹ״̬�Ĵ��ڲ��ܽ��������û���������Ϣ.
	WS_DLGFRAME : ����һ�����Ի���߿���Ĵ��ڡ����ַ��Ĵ��ڲ��ܴ���������
	WS_GROUP : ָ��һ����Ƶĵ�һ�����ơ�����������ɵ�һ�����ƺ������Ŀ�����ɣ��Եڶ������ƿ�ʼÿ�����ƣ�����WS_GROUP���ÿ����ĵ�һ�����ƴ���WS_TABSTOP��񣬴Ӷ�ʹ�û�����������ƶ����û�������ʹ�ù�������ڵĿ��Ƽ�ı���̽��㡣����
	WS_HSCROLL������һ����ˮƽ�������Ĵ��ڡ�
	WS_ICONIC������һ����ʼ״̬Ϊ��С��״̬�Ĵ��ڡ�
	��WS_MINIMIZE�����ͬ��
	WS_MAXIMIZE������һ����ʼ״̬Ϊ���״̬�Ĵ��ڡ�
	WS_MAXIMIZEBOX������һ��������󻯰�ť�Ĵ��ڡ��÷������WS_EX_CONTEXTHELP���ͬʱ���֣�ͬʱ����ָ��WS_SYSMENU���
	WS_OVERLAPPED : ����һ������Ĵ��ڡ�һ������Ĵ�����һ����������һ���߿���WS_TILED�����ͬ������WS_OVERLAPPEDWINDOW������һ������WS_OVERLAPPED��WS_CAPTION��WS_SYSMENU WS_THICKFRAME��WS_MINIMIZEBOX��WS_MAXIMIZEBOX���Ĳ�����ڣ���WS_TILEDWINDOW�����ͬ�� ����WS_POPUP������һ������ʽ���ڡ��÷������WS_CHLD���ͬʱʹ�á�
	WS_POPUWINDOW������һ������WS_BORDER��WS_POPUP, WS_SYSMENU���Ĵ��ڣ�WS_CAPTION��WS_POPUPWINDOW����ͬʱ�趨����ʹ����ĳ���ɼ�������
	WS_SIZEBOX������һ���ɵ��߿�Ĵ��ڣ���WS_THICKFRAME�����ͬ��
	WS_SYSMENU������һ���ڱ������ϴ��д��ڲ˵��Ĵ��ڣ�����ͬʱ�趨WS_CAPTION��񡣡���
	WS_TABSTOP������һ�����ƣ�����������û�����Tab��ʱ���Ի�ü��̽��㡣����Tab����ʹ���̽���ת�Ƶ���һ����WS_TABSTOP���Ŀ��ơ�
	WS_THICKFRAME������һ�����пɵ��߿�Ĵ��ڣ���WS_SIZEBOX�����ͬ��
	WS_TILED������һ������Ĵ��ڡ�һ������Ĵ�����һ�������һ���߿�
	��WS_OVERLAPPED�����ͬ��
	WS_TILEDWINDOW : ����һ������WS_OVERLAPPED��WS_CAPTION��WS_SYSMENU�� WS_THICKFRAME��WS_MINIMIZEBOX��WS_MAXMIZEBOX���Ĳ�����ڡ���WS_OVERLAPPEDWINDOW�����ͬ������
	WS_VISIBLE����һ����ʼ״̬Ϊ�ɼ��Ĵ��ڡ�
	WS_VSCROLL������һ���д�ֱ�������Ĵ��ڡ�


	�ڶ�ʮ����GetMessage��ȡ������Ϣ


	����CreateWindow�������ӣ��Ժ�����ӿ������ڿ���̨�£�Ҳ������Win32 Application������Ժ�����������жϸý�ʲô���̡�


	�ڶ�ʮ����RegisterClassע�ᴰ���࣬����CreateWindow


	�ڶ�ʮ�ĸ�UpdateWindow����CreateWindow


	�ڶ�ʮ���DispatchMessage����CreateWindow


	�ڶ�ʮ����LoadCursorFromFile�Ӵ��̼���һ������ļ����������ظù����


	����e������һ����Ϊa.cur�Ĺ���ļ���


	HCURSOR cursor//����һ������������ڴ��LoadCursorFromFile�������صĹ����


	cursor = LoadCursorFromFile("e:\\a.cur");


����˹������ʲô���أ���һ�´�����WNDCLASS���hCursor��Ա�������ԱҲ��һ��������������˰ɣ�


�ڶ�ʮ�߸�CreateSolidBrush����һ����ˢ���������ػ�ˢ���


HBRUSH hbr = CreateSolidBrush(RGB(12, 172, 59));//�������ֱַ����RGB����ɫֵ��RGB����������ɫֵ����һ��COLORREF���͵�ֵ


�ڶ�ʮ�˸�LoadImageװ��λͼ��ͼ�ꡢ��꺯��


�������壺HANDLE LoadImage(HINSTANCE hinst, LPCTSTR lpszName, UINTuType, int cxDesired, int CyDesired, UINT fuLoad)


��������ֻҪ��������ļ����򵥹��ܣ��Ӵ��̼���λͼ���Ӵ��̼���ͼ�꣬�Ӵ��̼��ع�ꡣ���Ե�һ������hinst���ǲ��ù�����ֱ����NULL���У��ڶ�������lpszName��ͼƬ�ļ�����·����������������uTypeָ��Ҫ���ص���ʲô���͵�ͼƬ��


��λͼ����IMAGE_BITMAP�������ǹ�꣨��IMAGE_CURSOR��������ͼ�꣨��IMAGE_ICON�������ĸ�cxDesired�͵��������CyDesired, ָ��Ҫ���ص�ͼƬ�Ŀ�ߣ����ԷŴ��꣬������С����������ص���λͼ�Ļ�����������������Ϊ0������������fuLoad��ʾ�Ժ��ַ�ʽ�����ļ������������ǴӴ��̼����ļ���������LR_LOADFROMFILE;


���ˣ�����e������һ��c.cur��i.ico�ļ������ӣ����ô���ͼ��͹�꣬���б���ɫ


#include "stdafx.h"//���ͷ�ļ��Ǳ������Զ����ɵģ����ǿչ��̣������У�
//�����ֱ�ӽ�C++Դ�ļ����������ͷ�ļ��������


#include <windows.h> 
#include <stdio.h> 
LRESULT CALLBACK WinSunProc(
	HWND hwnd, // handle to window 
	UINT uMsg, // message identifier 
	WPARAM wParam, // first message parameter 
	LPARAM lParam // second message parameter 
); //���ڹ��̺�������
int WINAPI WinMain(
	HINSTANCE hInstance, // handle to current instance 
	HINSTANCE hPrevInstance, // handle to previous instance 
	LPSTR lpCmdLine, // command line 
	int nCmdShow // show state 
)
{
	//���һ�������� 
	WNDCLASS wndcls;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = CreateSolidBrush(RGB(12, 172, 59));//��ˢ
	wndcls.hCursor = (HCURSOR)LoadImage(NULL, "e:\\c.cur", IMAGE_CURSOR, 24, 24, LR_LOADFROMFILE);//���ع��
	wndcls.hIcon = (HICON)LoadImage(NULL, "e:\\i.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE);//����ͼ��
	wndcls.hInstance = hInstance; //Ӧ�ó���ʵ�������WinMain���������� 
	wndcls.lpfnWndProc = WinSunProc; //���崰�ڴ�����
	wndcls.lpszClassName = "windowclass";
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls);


	//�������ڣ�����һ��������������ɹ��������ں󷵻صľ�� 
	HWND hwnd;
	hwnd = CreateWindow("windowclass", "first window",
		WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);
	//��ʾ��ˢ�´��� 
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
	//������Ϣ�ṹ�壬��ʼ��Ϣѭ�� 
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}


//��д���ڹ��̺��� 
LRESULT CALLBACK WinSunProc(
	HWND hwnd, // handle to window 
	UINT uMsg, // message identifier 
	WPARAM wParam, // first message parameter 
	LPARAM lParam // second message parameter 
)
{
	switch (uMsg)
	{
	case WM_CHAR: //�ַ���Ϣ
		char szChar[20];
		sprintf(szChar, "char code is %c", wParam);
		MessageBox(hwnd, szChar, "char", 0);
		break;
	case WM_LBUTTONDOWN: //������������Ϣ
		MessageBox(hwnd, "mouse clicked", "message", 0);
		break;
	case WM_CLOSE:
		if (IDYES == MessageBox(hwnd, "�Ƿ���Ľ�����", "message", MB_YESNO))
		{
			DestroyWindow(hwnd); //���ٴ��ڣ�������WM_DESTROY��Ϣ��������
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


�ڶ�ʮ�Ÿ�GetDC���ݴ��ھ����ȡ�豸�����ģ�DC������DC���


�õ���һ�����ڵ��豸�����ģ��Ϳ��Խ��л�ͼ�����ˣ���Բ���������Σ���ʾͼƬ�Ⱥ�������Ҫ�豸������(DC������������ġ�


	HDC dc//����һ��DC���


	HWND wnd = FindWindow(NULL, "�ޱ���.txt- ���±�");//��ȡ���ھ��


dc = GetDC(wnd)//��ȡ������ڵ��豸������


����ʮ��Rectnagle�ڴ����л�һ������


��"�ޱ���.txt - ���±�"����Ϊ������������ڼ򵥵Ļ�һ������


#include<windows.h>
void main()
{
	HDC dc;
	HWND wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
	dc = GetDC(wnd);//��ȡ�����豸�����ģ�DC��
	while (1)//��ѭ������ظ�������Ϊ��ȷ�����ᱻ����ˢ�¸�ˢ��
	{
		Rectangle(dc, 50, 50, 200, 200);//��һ������
		Sleep(200);
	}
}





http://hi.baidu.com/3582077/item/535b4211faa5df8f88a956e5


����ʮ��CreateToolhelp32Snapshot����ǰ������һ����


HANDLEhProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);


//��ס���ָ�ʽ�����ˣ����صľ�����洢�н�����Ϣ��������Process32Firs�����ҳ�����


����ʮһ��Process32First����CreateToolhelp32Snapshot�������صľ����ȡ������Ϣ


���Process32Next����ʹ�ã��е����ļ�Ѱ�Һ�����


���������ӣ���ʾϵͳ���������Լ�����ID��


#include<windows.h>
#include<tlhelp32.h>//�������պ�����ͷ�ļ�
#include<stdio.h>
int main()
{
	PROCESSENTRY32 pe32;//���̵���Ϣ����洢������ṹ��
	//��ʹ������ṹ֮ǰ�����������Ĵ�С
	pe32.dwSize = sizeof(pe32);
	//��ϵͳ�ڵ����н�����һ������
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);//��һ�β���
	while (bMore)
	{
		printf("��������:%s\n", pe32.szExeFile);//szExeFile�ǽ�����
		printf("����ID��:%u\n\n", pe32.th32ProcessID);//th32ProcessID�ǽ���ID��
		bMore = ::Process32Next(hProcessSnap, &pe32);//Ѱ���¸����̣���������0����û�н��̿�Ѱ
	}
	return 0;
}


����ʮ����OpenProcess���ݽ���ID�Ż�ý��̾�������ͨ����������


�������壺HANDLE OpenProcess(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId);


��һ��������Ҫ��������PROCESS_ALL_ACCESS���ڶ�������Ҳһ������FALSE�������һ���������ǽ���ID�š�


����ʮ����TerminateProcess����һ�����̣�����̾����������


�ú���ֻ��������������һ���ǽ��̾�����ڶ�����0�����ˡ�


���ڸ������ӣ����赱ǰ��һ��������Ϊabc.exe�Ľ����������У���һ�������������


#include<windows.h>
#include<tlhelp32.h>//�������պ�����ͷ�ļ�
int main(int argc, char *argv[])
{




	PROCESSENTRY32 pe32;
	//��ʹ������ṹ֮ǰ�����������Ĵ�С
	pe32.dwSize = sizeof(pe32);
	//��ϵͳ�ڵ����н�����һ������
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	//�������̿��գ�������ʾÿ�����̵���Ϣ
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
	while (bMore)
	{


		if (strcmp("abc.exe", pe32.szExeFile) == 0)//����ҵ�������Ϊabc.exe
		{
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);//��ȡ���
			::TerminateProcess(hProcess, 0);//������
		}
		bMore = ::Process32Next(hProcessSnap, &pe32);//Ѱ����һ��
	}
	return 0;
}


�����������ӣ�ֻ�ܽ�����ͨȨ�޽��̣����Ϊϵͳ���̵Ļ�����û���ã��������ˡ��ں��������Ȩ�޺�������������˵����ν���ϵͳ���̡�


����ʮ�ĸ�CreatePen����һ�����ʣ����ػ��ʾ����


�������壺BOOL CreatePen(int nPenStyle, int nWidth, COLORREFcrColor);


��һ����������ʾ��ʲô���͵��ߣ�ȡֵ�����£�


PS_SOLID ���ʻ�������ʵ�� PS_DASH ���ʻ����������ߣ�nWidth������1�� PS_DOT ���ʻ������ǵ��ߣ�nWidth������1��
PS_DASHDOT ���ʻ������ǵ㻮�ߣ�nWidth������1�� PS_DASHDOTDOT ���ʻ������ǵ� - �� - ���ߣ�nWidth������1��
�ڶ��������ǻ��ʵĿ�ȣ������������ǻ��ʵ���ɫ��COLORREF���Ϳ���RGB�������RGB(233, 128, 88); �ֱ��Ǻ�������


�紴��һ�����ʣ�HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 78, 99));


����ʮ���CreateSolidBrush����һ����ˢ


ֻ��һ��COLORREF���͵Ĳ���


HBRUSH brush = CreateSolidBrush(RGB(22, 182, 111));


����ʮ����SelectObject��GDI����ѡ����Ӧ��DC��


�񻭱�(���HPEN������ˢ��HBURSH����λͼ��HBITMAP���ȶ���GID������Ϊ��ͼ�������续Բ�������Σ���ֱ�ߣ�����������ͼ�Σ�Ĭ�����Զ��ǲ���ģ����ߵĿ�ȡ���ô��Ҫ�ı仭����ʱ�ߵĿ�ȣ��������뻭������ͼ�������������Ϊ5�����أ�����ô��Ҫ����һ�����Ϊ5�Ļ��ʣ�Ȼ����ͨ��SelectObject���������������ѡ�룬�Ϳ�����.


	���¾ٸ�����:SelectObjectӦ��




#include "stdafx.h"
#include<windows.h>
	LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 78, 99));//��������
	static HBRUSH brush = CreateSolidBrush(RGB(22, 182, 111));//������ˢ
	if (uMsg == WM_PAINT)//������Ҫ�ػ���ʱ��
	{
		HDC hDC;
		PAINTSTRUCT ps;
		hDC = BeginPaint(hwnd, &ps); //BeginPaintֻ������ӦWM_PAINT,������GetDC��ȡ�豸������
		SelectObject(hDC, pen);//ѡ�뻭��
		SelectObject(hDC, brush);//ѡ�뻭ˢ
		Rectangle(hDC, 100, 100, 200, 200);
		EndPaint(hwnd, &ps);
	}
	else if (uMsg == WM_CLOSE)//�û��ر��˴���
		DestroyWindow(hwnd);//���ٴ��ڣ�������WM_DESTROY��Ϣ
	else if (uMsg == WM_DESTROY)//������ڱ�����
		PostQuitMessage(0);//�ý����˳�
	return DefWindowProc(hwnd, uMsg, wParam, lParam); //δ�������Ϣͨ��DefWindowProc��������ϵͳ����
}
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{


	WNDCLASS wndcls; //����һ���洢������ϢWNDCLASS����
	wndcls.cbClsExtra = 0; //Ĭ��Ϊ0
	wndcls.cbWndExtra = 0; //Ĭ��Ϊ0
	wndcls.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); //������ˢ
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW); //���
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR); //����ͼ��
	wndcls.hInstance = hInstance; //Ӧ�ó���ʵ�������WinMain���������� 
	wndcls.lpfnWndProc = WinSunProc; //������Ϣ������
	wndcls.lpszClassName = "windowclass"; //��������
	wndcls.lpszMenuName = NULL; //���ڲ˵�����û�в˵���ΪNULL
	wndcls.style = CS_HREDRAW | CS_VREDRAW;//�������ͣ�CS_HREDRAW��CS_VERDRAW ����
	//������ˮƽ����ֱ����Ŀ�ȱ仯ʱ�ػ���������
	RegisterClass(&wndcls); //�Ѵ�����Ϣ�ύ��ϵͳ��ע�ᴰ����
	HWND hwnd; //���Դ洢CreateWindow�����������Ĵ��ھ��
	hwnd = CreateWindow("windowclass", "first windows",
		WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);//��������
	ShowWindow(hwnd, SW_SHOWNORMAL);//���ڴ������ˣ���ʾ��
	UpdateWindow(hwnd); //���´��ڣ��ô��ں����ӳٵ���ʾ
	MSG msg;//��Ϣ�ṹ����
	while (GetMessage(&msg, NULL, 0, 0))//��ȡ��Ϣ
	{
		//TranslateMessage(&msg); //�˺������ڰѼ�����Ϣ(WM_KEYDOWN,WM_KEYUP)ת�����ַ���ϢWM_CHAR
		DispatchMessage(&msg); //����������ô��ڹ��̴�����������MSG�����Ϣ����󴫸����̺������ĸ�����
	}
	return 0;
}


����ʮ�߸� ReadProcessMemory���ݽ��̾����ȡ��Ӧ��һ���ڴ棨��������������ڴ棩


�������壺BOOL ReadProcessMemory(HANDLE hProcess, PVOIDpvAddressRemote, PVOID pvBufferLocal, DWORD dwSize,


	PDWORD pdwNumBytesRead); �ܹ��ĸ�����


	��һ������hProcess��Զ�̽��̾��������ȡ�� ���ڶ���pvAddressRemote��Զ�̽������ڴ��ַ�� �Ӿ���δ���ȡ


	pvBufferLocal�Ǳ��ؽ������ڴ��ַ.��������ȡ������д��˴���dwSize��Ҫ��ȡ���ֽ�����Ҫ��ȡ����


	pdwNumBytesRead��ʵ�ʶ�ȡ�����ݣ�����ִ�к�ʵ�ʶ��˶����ֽڣ����洢�ڸñ����


	Զ�̽��̵��ڴ��ַ��ʲô��˼�أ����������ڶ���һ������a, int a; �����ˣ����֪��int����ռ�ĸ��ֽڵģ�Ҳ����˵���a������ռ���ڴ���ʼ��ַ��0x1234, ��ô����a��ռ��0x1234, 0x1235, 0x1236, 0x1237���ĸ��ֽڣ����ĸ��ֽڵ����ݾ�����a������ֵ��


	����֪������������Ǿ����ٸ����ӣ���ȡ��һ��������һ��������ֵ���������������һ�����ڶ���Read)һ�����ڱ���(BeRead);


��ôҪ��λ����һ��������һ�������ĵ�ַ�� ? ����������һ���򵥵ķ���������һ�������Լ�ȥ��ȡ��Ȼ�������ֵַ��


�����ĳ���������£�����ý�����Ϊ��BeRead.exe
#include<stdio.h>
int main()
{
	int a = 10;//Ҫ��ȡ�ı�����
	printf("%x\n", &a);//��������������ʼ��ַ���������Ϊ12ff7c
	while (1)
	{
		Sleep(1000);
	}


	return 0;
}


������������������У�Ȼ���������ĵ�ֵַ������������ĳ��������ֵַ��


��ȡ�ĳ���������£�


#include<windows.h>
#include<stdio.h>
#include<tlhelp32.h>
int main()
{


	//��Ҫ��ȡ���̾������λ�ȡ������TerminateProcess����������һ������


	HANDLE ReProcess;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
	while (bMore)
	{
		if (strcmp(pe32.szExeFile, "BeRead.exe") == 0)//�����BeRead.exe
		{
			ReProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);//��ȡ�ý��̾��
			break;
		}
		bMore = Process32Next(hProcessSnap, &pe32);
	}
	int *ReAddress = (int *)0x12ff7c;//Ҫ��ȡ���ڴ�ĵ�ֵַ
	int *p = new int;
	unsigned long size;
	ReadProcessMemory(ReProcess, ReAddress, p, 4, &size);//��ȡBeRead���̵��ڴ�
	printf("%d\n", *p);//�����ȡ����ֵ
	return 0;
}


����ʮ�˸�WriteProcessMemory���ݽ��̾��д����Ӧ��һ���ڴ棨д��������������ڴ棩


���������Ĳ�����ReadProcessMemory����������˼һ����ֻ����һ����д��һ���Ƕ���


����ֱ�Ӿٸ����ӣ���ʽ�����ڴ溯��������һ����


��д�ĳ���������£�����ý�����Ϊ��BeWrite.exe


#include<stdio.h>
int main()
{
	int a = 10;
	printf("%x\n", &a);//�������Ϊ12ff7c
	while (1)
	{
		printf("%d\n", a);//ÿ��һ��������鿴ֵ��û�иı�
		Sleep(1000);
	}


	return 0;
}


д��Ĵ������£�


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


����ʮ�Ÿ�CreateThread����һ���̣߳����̣߳�


�߳���ʲô��˼�أ����������߳���ִ�еģ�һ������Ĭ��ֻ��һ���̣߳����̣߳�������ȷ����߳̾ͺñ�һ���ˣ�����ͬ���ܵĴ�������ͺ���һ������ͬ�����飬��ϴ�룬ϴ�·������ء�һ����Ҫ���⼸���������꣬�����кü��ַ�������һ�־��ǣ�ϴ���룬��ȥϴ�·����·�ϴ���ˣ���ȥ���ء��ڶ��־��ǣ�ϴһ�����룬��ȥϴһ�����·�����ȥ��һ���ӣ�Ȼ����ȥϴһ�����·�.......ֱ�����ꡣ���ˣ�����������ٴ���һ���˰������£���������˺���ͽ���ϴ�·��������ϴ�룬���������¾Ϳ���ͬʱ�����ˡ�������Ĵ���һ����ָ�ľ���CreateThread������


�������壺HANDLE CreateThread(LPSECURITY_ATTRIBUTESlpThreadAttributes, DWORD dwStackSize, LPTHREAD_START_ROUTINElpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);


�ú�����������������һ���������ù�������NULL���ڶ�������dwStackSize�������̵߳ĳ�ʼ��ջ��С��Ĭ��Ϊ0��������lpStartAddress�������ָ�꣩��������������������̶ֹ���ʽ��DWORD _stdcall ThreadProc(LPVOID lpParameter), �µ��߳̽���ִ�������������Ĵ��룬ֱ�������������߳����������ĸ�lpParameter��һ�Զ���������û�����ͨ�����������������Ҫ�����ͣ�����������̺߳����Ĳ������Ӧ�������dwCreationFlags��0��ʾ����ִ�У������CREATE_SUSPENDED��ʾ����ֱ����ResumeThread�������ѡ�������lpThreadId��NULL�����ˡ�


�־ٸ����ӣ������߳�ͬʱÿ��һ�����һ�����֣�Ҳ����һ����������������


#include<windows.h>
#include<stdio.h>
DWORD _stdcall ThreadProc(LPVOID lpParameter)//�߳�ִ�к���
{
	int si = 100;
	while (si > 0)
	{
		printf("���߳��������:%d\n", si--);
		Sleep(1000);
	}
	return 0;
}


int main()
{
	int mi = 0;
	CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);//����һ���̣߳�ȥִ��ThreadProc����
	while (mi < 100)
	{
		printf("���߳��������:%d\n", mi++);
		Sleep(1000);
	}
	return 0;
}


����ʮ��GetCurrentProcessId��õ�ǰ����ID


DWORD currentPID;
currentPID = ::GetCurrentProcessId();//���ؽ���ID��
cout << currentPID << endl;





http://hi.baidu.com/3582077/item/1e77f39fbee5b1de1f4271e3


����ʮһ��CreateCompatibleDC����һ�����ݵ��ڴ��豸�����ģ�DC��


����DC����һ�����ݵ��ڴ�DC����ʱ����������ڴ�DC������һЩ���Ը�ԴDCһ������DC�Ĵ�С���Լ���Ӧ���ڵĿ�ߵȡ��ڴ�DC�������û�о���ȡֵ������������������������ݸ�ֵ��


����ʮ����GetObject��ȡһ��������Ϣ����λͼ��ͼ�꣬��꣩


�������壺int GetObject(HGDIOBJ hgdiobj, int cbBuffer, LPVOIDlpvObject)��


��һ������hgdiobj�Ƕ��������ڶ�������cbBuffer�Ǵ�д��lpvObjectָ��ָ�򻺴������ݴ�С������������lpvObject��һ��ָ�룬ָ��һ����������


�����һ����ȡλͼ����Ϣ����ȡλͼ�Ĵ�С������E������һ��aa.bmp��λͼ�ļ������λͼ�Ŀ��


#include<windows.h>
#include<stdio.h>
int main()
{
	BITMAP bmInfo;//����ṹ�洢λͼ��Ϣ
	HBITMAP bmp;
	bmp = (HBITMAP)LoadImage(NULL, "e:\\aa.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	GetObject(bmp, sizeof(BITMAP), &bmInfo);
	printf("λͼ��%d,λͼ�ߣ�%d\n", bmInfo.bmWidth, bmInfo.bmHeight);
	return 0;
}


����ʮ����BitBlt�ڴ������һ��λͼ


��ʵ������˵���BitBlt�����ǿ���һ���豸�����ģ�DC�������ߺϲ��������ڣ�������һ�£��ϲ�����ͼƬ��Ҳ���޲��ɣ�������˵�������ѵ�����ͼƬ���ý���������Ѵ��ڽس�ͼƬ���������ڱ����ͼƬ�������е�Ϲ˵����һ��ǰ��ձ�׼���ɣ���������ֻҪ����������������ˣ������������Ҳ������ʲôӰ�죬�Ǿ��㹻�ˡ�


BitBlt�����ø�������ͼƬ����һ��һ�����ϲ�����ͼƬ����������ͼƬ��С��һ��Ҳ���Ժϲ������ϲ�DC�Ͳ����ˣ�����������Ϣһ����DC�ſ��Ժϲ�����Ҫ���ȷ������DCһ���أ����Ҫ�õ�CreateCompatibleDC�����ˡ�


�������壺BOOL BitBlt(HDC hdcDest, int nXDest, int nYDest, intnWidth, int nHeight, HDC hdcSrc, int nXSrc, int nYSrc, DWORD dwRop)��


��һ������hdcDest��ԭDC����������ǵ�DC��nXdest, nYDest, nWidth, nHeight���ĸ�������ָ����һ�����Σ�����ԭDC�Ŀ�����


����������hdcSrc�Ǹ��ǵ�DC�����nXSrc, nYSrc����ָ�������￪ʼ���ǡ�������DC�����Ͻǣ����ھŸ�����dwPop��ʾ�Ժ��ַ�ʽ���ǡ���Ϊ��������ֻҪ���һ��λͼ��������SRCCOPY, ֱ�Ӹ��ǡ�


���ˣ�ֱ�Ӿٸ����ӣ��ڴ������һ��ͼƬ������e������һ��aa.bmp��λͼ��Ϊ�˷��㣬����ֱ���ڼ��±��������λͼ��������һ��������Ϊ"�ޱ���.txt - ���±�"���±����ڳ���


#include<windows.h>
#include<stdio.h>
int main()
{
	BITMAP bmInfo;//����ṹ�洢λͼ��Ϣ
	HBITMAP bmp;
	bmp = (HBITMAP)LoadImage(NULL, "e:\\aa.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	GetObject(bmp, sizeof(BITMAP), &bmInfo);//��ȡλͼ��Ϣ
	HWND wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
	HDC hdc = GetDC(wnd);
	HDC memDC = ::CreateCompatibleDC(hdc);//������ݵ�DC
	SelectObject(memDC, bmp);//ѡ��λͼ
	while (1)
	{


		BitBlt(hdc, 0, 0, bmInfo.bmWidth, bmInfo.bmHeight, memDC, 0, 0, SRCCOPY);//���λͼ
		Sleep(200);


	}
	return 0;


}


�������һ��BitBlt�������һ�������ĳ���ȡֵ����˼��


�ο����ٶȣ�
BLACKNESS����ʾʹ���������ɫ�������0��ص�ɫ�������Ŀ��������򣬣���ȱʡ�������ɫ����ԣ�����ɫΪ��ɫ��������
DSTINVERT����ʾʹĿ�����������ɫȡ����
MERGECOPY����ʾʹ�ò����͵�AND���룩��������Դ�����������ɫ���ض�ģʽ���һ�� ����MERGEPAINT��ͨ��ʹ�ò����͵�OR���򣩲������������Դ�����������ɫ��Ŀ������������ɫ�ϲ��� NOTSRCCOPY����Դ����������ɫȡ�����ڿ�����Ŀ���������
NOTSRCERASE��ʹ�ò������͵�OR���򣩲��������Դ��Ŀ������������ɫֵ��Ȼ�󽫺ϳɵ���ɫȡ���� PATCOPY�����ض���ģʽ������Ŀ��λͼ�ϡ�
PATPAINT��ͨ��ʹ�ò���OR���򣩲�������Դ��������ȡ�������ɫֵ���ض�ģʽ����ɫ�ϲ���Ȼ��ʹ��OR���򣩲��������ò����Ľ����Ŀ����������ڵ���ɫ�ϲ���
PATINVERT��ͨ��ʹ��XOR����򣩲�������Դ��Ŀ����������ڵ���ɫ�ϲ���
SRCAND��ͨ��ʹ��AND���룩����������Դ��Ŀ����������ڵ���ɫ�ϲ���
SRCCOPY����Դ��������ֱ�ӿ�����Ŀ���������
SRCERASE��ͨ��ʹ��AND���룩��������Ŀ�����������ɫȡ������Դ�����������ɫֵ�ϲ��� ����SRCINVERT��ͨ��ʹ�ò����͵�XOR����򣩲�������Դ��Ŀ������������ɫ�ϲ�������
SRCPAINT��ͨ��ʹ�ò����͵�OR���򣩲�������Դ��Ŀ������������ɫ�ϲ���
WHITENESS��ʹ���������ɫ��������1�йص���ɫ���Ŀ��������򡣣�����ȱʡ�����ɫ����˵�������ɫ���ǰ�ɫ��


����ʮ�ĸ�GetWindowText���ݴ��ھ����ô��ڱ�����


�������壺int GetWindowText(HWND hWnd, LPTSTR lpString, intnMaxCount);


��һ������hWnd��Ҫ��ȡ���ڱ������Ĵ��ھ�����ڶ���lpString�Ǹ��ַ��������ڱ�����������洢�������棬����������nMaxCountָ���˵ڶ��������ַ�����Ĵ�С��


������GetCursorPos��WindowFromPoint�ٸ����ӣ����ָ���ĸ����ڣ����ڽ�����ʾ�Ǵ��ڵı�����


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


����ʮ���SetWindowText���ݴ��ھ�����ô��ڱ�����


�������������������һ���Ǵ��ھ����һ���Ǳ�����������Ͳ���Ҫ�����˰ɣ�ֱ�ӿ����ӣ�����һ�����ڱ�������������


"�ޱ���.txt - ���±�"Ϊ����


#include<windows.h>
#include<stdio.h>
int main(int argc, char* argv[])
{
	HWND wnd;
	wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");//��ȡ���ھ��
	SetWindowText(wnd, "�µĴ��ڱ���");//���ô��ڱ�����
	return 0;
}


����ʮ����GetCurrentProcess��õ�ǰ�߳̾��


û�в�����ֱ�ӵ��ü��ɣ��ú��������߳̾��


����ʮ�߸�OpenProcessToken���һ�����̵ķ������ƾ��


���һ�����̵ķ���������ʲô���أ���Ҫ��Ϊ���޸�����Ȩ�ޣ�ǰ���ڽ��ܽ���һ�����̵�ʱ��˵���ˣ��޷�����ϵͳ���̣���ʲôԭ���أ�ԭ���ǵ���OpenProcess����ʧ�ܣ��޷���ȡϵͳ���̾��������ģ���Ϊʲô��ʧ���أ�Ȩ�޲�������ͨ����Ľ���û��SeDeDebugȨ�ޣ���һ�����̵�Ȩ���������������صģ���������ֻҪ��ȡһ�����̵ķ������ƾ��������������Ϊ����������Ӧ�ĺ����������̵�Ȩ��ΪSeDeDebug�Ϳ��Ի�ȡϵͳ���̾����������������


�������壺BOOL OpenProcessToken(HANDLE ProcessHandle, DWORDDesiredAccess, PHANDLE TokenHandle)


��һ������ProcessHandle����ȡ�Ľ��̾�����ڶ�������DesiredAccess�������ͣ���TOKEN_ADJUST_PRIVILEGES�����ˣ�


������TokenHandle�Ƿ������ƾ����ָ�룬�ò������վ����


���ñ����̵ķ������ƾ����HANDLE hToken;


OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);


����ʮ�߸�LookupPrivilegeValue�����鿴��ӦϵͳȨ�޵���Ȩֵ��������Ϣ��һ��LUID�ṹ����
���潲���ˣ�������Ȩ��һ˵����ô���Ҳ�ܲµ�������Ȩ�޵���ϢҲһ���洢��һ���ṹ�������ṹ�������˽���Ȩ����ص�һЩ��Ϣ������ṹ��������Ͳ����������ˣ�������Ҫ���ģ�ֻ�ǰ�һ������Ȩ�����ó�SeDeDebug�����ˣ���������ֻҪ֪��TOKEN_PRIVILEGES������������Ȩ�޵Ľṹ��Ϳ����ˡ���LookupPrivilegeValue�����Ǹ��ݷ������ƾ��ȡ��Ӧ��Ȩ����Ϣ��
���ǵġ�TOKEN_PRIVILEGES�ṹ���Privileges[0].Luid�������������ѯ�Ķ������Ӧ��Ҳ����˵�����������SeDeDeBugȨ�ޣ���Privileges[0].Luid��ȡֵ���������أ���LookupPrivilegeValue��������Ի�ȡ��ȡֵ��
�����������������ģ�BOOL LookupPrivilegeValue(LPCTSTRlpSystemName, LPCTSTR lpName, PLUID lpLuid);
��һ������lpSystemNameͨ������NULL������ϵͳ���ã��ڶ�������lpName��Ҫ��ѯ��Ȩ��������Ҫ��ѯ����SeDeDebugȨ����ȡֵ��SE_DEBUG_NAME������������lpLuid������ȡֵ��
��LUIDluid; LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid);


����ʮ�˸�AdjustTokenPrivileges����һ�����̵ķ���������Ϣ��Ȩ�ޣ�


�������壺BOOL AdjustTokenPrivileges(HANDLE TokenHandle, BOOLDisableAllPrivileges, PTOKEN_PRIVILEGES NewState, DWORDBufferLength, PTOKEN_PRIVILEGES PreviousState, PDWORD ReturnLength)


��һ������TokenHandle�����ƾ�����ڶ����ǽ�������Ȩ�ޱ�־��������FALSE�����ˡ�������NewState�Ǵ�ˢ�����ƾ����PTOKEN_PRIVILEGES�ṹ��Ϣָ�룬���ĸ�BufferLengthָ��TOKEN_PRIVILEGES�ṹ��С�����壬����������NULL�����ˡ�


��ô���������������������һ������Ȩ���ƣ������ܹ�����ϵͳ���̵Ĵ�����ǣ�


HANDLE hToken;
OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);
TOKEN_PRIVILEGES tp;
LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
tp.PrivilegeCount = 1;//tp������һЩ��������
tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), NULL, NULL);


ֻҪ������Ĵ��룬���������ͨ�������ӵ�ǰ�棬��ô���ܽ���ϵͳ�����ˡ�


����ʮ�Ÿ�LoadLibrary���ض�̬���ӿ⣬���ض�̬���ӿ�ģ����


�ú���ֻ��һ���������Ǿ��Ƕ�̬���ӿ�����ƣ���user32.dll����������HMOUDLE���͵�ģ�����������һ����̬���ӿ��ģ�������Ϳ��Ե���GetProcAddress�������ģ������ĺ�����ַ���Ӷ����ö�̬���ӿ���ĺ�����


����ʮ��GetProcAddress����ģ������ȡ��Ӧ�ĺ�����ַ


�ᵽGetProcAddress���������ò���һ����ô���һ����̬���ӿ⣬�������Ǿ����Լ���ƶ�̬���ӿ���ΪGetProcAddress���������ӡ�


��̬���ӿ���ĺ��������ͷ�ļ��ĺ�����ʲô�����أ�����ʡ�ڴ棬����ڱȽϳ��õĺ������ѡ������һ�����������һ��ͷ�ļ���ĺ����Ļ����ǲ�����Σ������Ĵ���ͻᱻ����һ�ݵ���ǰ��������ԣ�����ʮ�����������ͬһ��������ʱ������������ڴ�����ռ�õĿռ䣬�ͻ���ʮ���ݣ��ֱ��ڸ��Ե��õĽ����ڴ�ռ������̬���ӿ�ĺ�����ֻ���ڴ�����һ�ݿռ䣨���ÿռ䣩����ĸ�����Ҫ�õ���������Ļ���ֻҪ����������ĵ�ַ�����̾Ϳ����ܵ�����ռ�ִ�к�������ô��λ�ȡ������ַ�أ���GetProcAddress���������ˡ�


�������Ǿ��Լ����һ����̬���ӿ⣬�㡰�ļ�->�½�->����",Ȼ��ѡ�С�Win32Dynamic-Link Library��,�����ұ߸�����ȡһ��������ȷ�������ŵ�����һ���Ի���ѯ��ϣ������ʲô���ͣ�����ѡ��ڶ�����һ���򵥵�DLL���̡��������->ȷ��.Ȼ�󵥻��ұߵġ�+���ţ���С��һ����������������һ��Globals��" + "�ţ������üӺţ�Ȼ����˫��DllMain�������������༭�����������д���룬�����Ѿ�����һЩ�����ˣ��������Զ����ɵġ��Ǹ�DllMain���������Ƕ�̬���ӿ�����������ڳ�����̼��ض�̬���ӵ�ʱ�򣬽��̻��Զ�����DllMain������Ҳ����˵���Զ�ִ��DllMain������Ĵ��룬Ҳ����˵������ĳ���ִ���������䡰LoadLibrar("user32.dll")", ��ôִ��������Ľ��̣�����Զ�ִ��user32.dll���DllMain��������������̼߳��ض�̬��Ļ�����ô��DllMain������Ĵ���ᱻִ�����Σ��ֱ��Ǽ��ص�ʱ��ִ��һ�Σ�����FreeLibrary�����ͷŻ��������Զ��ͷŶ�̬���ӿ��ʱ��ִ��һ�Σ�������ʲôԭ����DllMain���������ã�DllMain�����ĵڶ�������ul_reason_for_call˵����ԭ�������ĸ�ȡֵ���������ĸ�ԭ�򡣷ֱ��ǣ�


DLL_PROCESS_ATTACH�����̼��أ���DLL_THREAD_ATTACH���̼߳��أ�


DLL_THREAD_DETACH���߳��ͷţ���DLL_PROCESS_DETACH�������ͷţ�


��Ϊ��������ֻҪ���һ����̬���Ӻ��������Ա㲻�ù�DllMain������DllMain���������ڽ���CreateRemoteThread������һ��Զ���̣߳�������ʱ�򽲵�����������ֻҪ��DllMain�����ⶨ��һ�����������ˡ�


��ô�ڶ�̬���ӿ�����ζ��庯���أ������������Ҫ�����Ļ��������ͨ��������ûʲô������������ʲô��˼�����ǿ�����GetProcAddress������ȡ��ַ�ĺ������ǵ����ĺ���Ҫ��ζ����أ�
ֻҪ�ں���ǰ�����extern "C" __declspec(dllexport)�����ˣ�����������������ֹ��������������ô�������;ٸ����ӡ�


��̬������Ĵ��룺


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


�����ִ�У�Ȼ��ͻᵯ��һ�����ԶԻ���ֱ�ӵ�ȡ�������ű������˶�̬���ӿ�DLL��Ȼ����Ĺ�����Ѻ�׺��Ϊdll���ļ��ҵ���


λ����MyProject\"��Ĺ�����"\Debug�¡����Ű�����ļ����Ƶ�Ҫ���õĹ����£�����ֱ�Ӹ���C:\windows\system32Ŀ¼�¡�


��������ļ���Ϊ"sss.dll", ��ôҪ���������Add�����������´��룺


HMODULE hmod = ::LoadLibrary("sss.dll");//��ȡsss.dll��ģ�飬����sss.dll��̬���ӿ�
typedef int(*pAdd)(int a, int b);//����һ����Ӧ�ĺ��������ͣ��Ա㶨���ת��
pAdd add = (pAdd)GetProcAddress(hmod, "Add");//��ȡhmodģ�����Add������ַ
int a = add(3, 5);//����ģ�����Add����





http://hi.baidu.com/3582077/item/9c29483b581f53c5392ffa19


����ʮһ��SetWindowsHookEx��װһ������


WINDOWS�ǻ�����Ϣ��ϵͳ������ƶ������������̰��������ڹرյȶ��������Ӧ����Ϣ����ô������ʲô��˼�أ������Լ��һ����Ϣ��������һ�������ﵥ����һ�£����Ȼ�������Ϣ�ģ�����Ӧ�ó��򣬶���ϵͳ��ϵͳ��ȡ�����Ϣ�󣬾�ȥ�鿴�����Ϣ�����ĸ����ڲ����ģ��ҵ����ں��ٰ���ϢͶ�ݵ���Ӧ���������Ϣ�������֮����һ�����ݹ��̣���ô���ӵ����þ�������Ϣ����Ӧ�ó���֮ǰ�ػ��������ӿ��Թ���һ�����������Ӵ���������Ҳ����˵�������һ�����̰�װ��һ�����ӣ������ٽ��յ���Ӧ����Ϣ֮ǰ������ȥִ�й����������ĺ�����


������һ������������壺


HHOOK WINAPI SetWindowsHookEx(int idHook, HOOKPROClpfn, HINSTANCE hmod, DWORD dwThreadId)


��һ������idHookָ��Ҫ��װ�Ĺ������ͣ���WH_KEYBOARD(���̹��ӣ���WH_MOUSE(��깳�ӣ����ڶ��������ǹ��Ӵ������ĵ�ַ���ú������������̶ֹ��ĸ�ʽ��LRESULT WINAPI HookProc(int nCode, WPARAM wParam, LPARAM lParam)


	����������hmod�ǹ��Ӻ�������ģ��ľ�������ĸ�����dwThreadId���߳�ID����������Ϣ��ID�����Ϊ0����Ϊȫ�ֹ��ӣ�����������Ϣ


	�ã����������Ǿ�һ�����ӣ���������ΪWH_KEYBOARD, ȫ�ֹ��ӡ��ػ���̰�����Ϣ�����ӵ�����Ϣ���ü���ʧ�顣


	������װ����ȫ�ֹ��ӣ����Թ��Ӵ�����������ڶ�̬���ӿ����ô���Ǿ����һ����̬���ӿ�ɡ�


	�ָ�����̬���ӿ�����д��룺(KeyDll.dll)


#include "stdafx.h"
#include<windows.h>
	BOOL APIENTRY DllMain(HANDLE hModule,
		DWORD ul_reason_for_call,
		LPVOID lpReserved
	)
{
	return TRUE;
}
HMODULE WINAPI ModuleFromAddress(PVOID pv)//�ú��������ڴ��ַ����������ڵ�ģ����
{
	MEMORY_BASIC_INFORMATION mbi;
	VirtualQuery(pv, &mbi, sizeof(mbi));
	return (HMODULE)mbi.AllocationBase;
}
LRESULT CALLBACK HookKey(int nCode, WPARAM wParam, LPARAM lParam)
{
	return TRUE;//�����棬�ӵ�����Ϣ
}
extern "C" __declspec(dllexport) void SetHook(void)
{
	SetWindowsHookEx(WH_KEYBOARD, HookKey, ModuleFromAddress(HookKey), 0);
}


����dll�ļ��󣬰������Ƶ���Ӧ��Ŀ¼��ȥ��


���½�һ�����̣������ö�̬���ӿ���ĺ������������£�


#include<windows.h>
int main()
{
	HMODULE hMod = LoadLibrary("KeyDll.dll");
	typedef void(*pSetHook)(void);
	pSetHook SetHook = (pSetHook)GetProcAddress(hMod, "SetHook");
	SetHook();
	while (1)
	{
		Sleep(1000);//�������������Զ��ͷŶ�̬���ӿ�
	}
	return 0;
}


������������һ�����󣬽��ոð�����Ϣ�Ľ��̣�����ȥִ�й��Ӵ�������Ȼ���ٴ�����Ϣ�������Ӵ������ļ�������˵���˰�������ϸ��Ϣ���簴���ĸ������ǰ��£�KEYDOWN�������ɿ���KEYUP�����������Ȥ�Ļ����������ǹ��Ӵ������Ĵ��뻻���������


LRESULT CALLBACK HookKey(int nCode, WPARAM wParam, LPARAMlParam)
{
	char sz[25];
	sprintf(sz, "%c", wParam);//�������ͷ�ļ�#include<stdio.h>
	MessageBox(NULL, sz, sz, MB_OK);
	return FALSE;
}


ÿ����һ�������ͻᵯ��һ����ʾ�򣬲���������µļ���ֻ���ַ������á�


����ʮ����SHGetFileInfo��ȡһ���ļ��ĸ�����Ϣ���ļ�����ͼ�꣬���Եȣ�
�������壺 DWORD SHGetFileInfo(LPCSTR pszPath, DWORDdwFileAttributes, SHFILEINFOA FAR *psfi, UINT cbFileInfo, UINT uFlags);
pszPath���ļ���·����dwFileAttributesһ��ȡ0�������Ҫ��ȡ�ļ�����Ϣ�Ļ�����ȡֵΪFILE_ATTRIBUTE_DIRECTORY��psfi��һ��SHFILEINFO�ṹ��ָ�룬�ýṹ�洢�ļ���Ϣ���������£�
typedef struct _SHFILEINFOA
{
	HICON hIcon; // �ļ�����ͼ����
	int iIcon; // ϵͳͼ���б�����
	DWORD dwAttributes; // �ļ�������
	CHAR szDisplayName[MAX_PATH]; // �ļ���·����
	CHAR szTypeName[80]; // �ļ���������������bmp�ļ�������ִ���ļ�exe����������
} SHFILEINFO;
���ĸ�����cbFileInfoָ��SHFILEINFO�ṹ�Ĵ�С����sizoef(SHFILEINFO);
���һ������uFlagsָ����ȡ�ļ���ʲô��Ϣ����ѡȡֵ���£�����Ӧ��SHFILEINFO��ĳ�Ա��
SHGFI_ICON; //���ͼ��
SHGFI_DISPLAYNAME; //�����ʾ��
SHGFI_TYPENAME; //���������
SHGFI_USEFILEATTRIBUTES; //�������
SHGFI_LARGEICON; //��ô�ͼ��
SHGFI_SMALLICON; //���Сͼ��
SHGFI_PIDL; // pszPath��һ����ʶ��
���磬��ֻҪ��ȡ�ļ�ͼ�꣬��ô������SHGFI_LARGEICON�����ˡ���������ȡ�ļ�������ͼ�꣬�����ȡ�ļ�����������ô����
SHGFI_LARGEICON | SHGFI_TYPENAME;
�������ӣ�
SHFILEINFO sfi;
SHGetFileInfo("e:\\aa.bmp", 0, &sfi, sizeof(sfi),
	SHGFI_ICON | SHGFI_LARGEICON | SHGFI_USEFILEATTRIBUTES | SHGFI_TYPENAME);


���ſ�����DrawIcon���������ļ�����ͼ�꣺�ú������壺BOOLDrawIcon��HDC hDC��int X��int Y, HICON hlcon);


����ʮ����RegCreateKeyEx��ע����ﴴ��һ���Ӽ������ȡһ���Ӽ��ľ��
���������������˽�һ��ע���Ļ�����������жԻ�������regedit��Ȼ��س��������ע���༭��������ӳ����ǰ�ģ������������
HKEY_CLASSES_ROOT
HKEY_CURRENT_USER
HKEY_LOCAL_MACHINE
HKEY_USER
HKEY_CURRENT_CONFIG


�ڸ���������������ˣ���HKEY_CURRENT_CONFIG�������������������ֱ���Software��System�����ܻ᲻һ����, ��ô����������ʲô�أ����ˣ����Ǹ� RegCreateKeyEx������ص��Ӽ����Ӽ�������Ǿ���ļ�ֵ���ˣ���Ҳ���������Ӽ�����ֵ�����ֿ�ѡ���ͣ��ֱ��ǣ��ַ���ֵ��REG_SZ)��������ֵ��REG_BINARY����DWORDֵ��REG_DWORD�������ַ���ֵ��REG_MULTI_SZ���Ϳ������ַ�ֵ��REG_EXPAND_SZ������ֵ���������Ϣ���������ƣ����ݡ�


�˽���������Щ���������ž����˽���RegCreateKeyEx�����ĸ���������, ������һ�º������壺


LONG RegCreateKeyEx(


	HKEY hKey,//���������ָ��Ҫ���ĸ������´����Ӽ�����������ȿ�
	LPCSTR lpSubKey,//�Ӽ�������������·����
	DWORD Reserved, .//һ��ȡ0
	LPSTR lpClass,//һ��ȡNULL
	DWORD dwOptions,//�����Ӽ�ʱ��ѡ��,��ѡֵREG_OPTION_NON_VOLATILE��REG_OPTION_VOLATILE������ȡ0�ȿ�
	REGSAM samDesired,//�򿪷�ʽ����KEY_ALL_ACCESS�����κ�������С�
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,//ָ���̳���,����ȡ0
	PHKEY phkResult,//�Ӽ���Ӧ�������������򿪵��Ӽ�������洢�ڸþ����
	LPDWORD lpdwDisposition//�򿪻��Ǵ����Ӽ�,��ӦREG_CREATED_NEW_KEY��REG_OPENED_EXISTING_KEY
);


�������һ�����ӣ��Ա������ܸ��õ����ú�����


��HKEY_CURRENT_CONFIG�����µ�Software�����ﴴ��һ����ΪMySelf���Ӽ���


#include<windows.h>
int main()
{
	HKEY hroot;//�Ӽ����
	DWORD dwDisposition;//��Ӧ�����һ������
	RegCreateKeyEx(HKEY_CURRENT_CONFIG, "Software\\MySelf", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hroot, &dwDisposition);
	return 0;
}


����ʮ�ĸ�RegSetValueEx�����Ӽ���������´������޸�һ����ֵ


�������壺LONG RegSetValueEx(
	HKEY hKey, // �Ӽ����
	LPCTSTR lpValueName, // ��ֵ���ƣ�����ṩ���Ӽ���û�и����ƣ��򴴽�
	DWORD Reserved, // ��������0
	DWORD dwType, // ��ֵ���ͣ�
	CONST BYTE *lpData, // ��ֵ������
	DWORD cbData // ��ֵ�����ݵĴ�С
);


�������������ӿ���������Ϊ��������һ�º�������δ���һ����ֵ�ģ�����֪�����������ӿ���������һ�㶼��


HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run�����һ����ֵ����ֵ����Ϊ�����ƣ�REG_SZ��������ֵ�����ݾ�ΪҪ�����������·����


����e������һ��AutoRun.exe��Ӧ�ó����õ��Կ���ʱ�Զ���������


#include<windows.h>
int main()
{
	HKEY hroot;//�Ӽ����
	DWORD dwDisposition;
	RegCreateKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0,
		NULL, 0, KEY_ALL_ACCESS, NULL, &hroot, &dwDisposition);
	RegSetValueEx(hroot, "AutoRun", 0, REG_SZ, (BYTE*)"e:\\AutoRun.exe", sizeof("e:\\AutoRun.exe"));
	return 0;
}


����ʮ���RegDeleteValue�����Ӽ����ɾ�����µ�һ����ֵ


����ֱ�Ӿ�һ�����ӣ�ɾ��RegSetValueEx���������ļ�ֵ


#include<windows.h>
int main()
{
	HKEY hroot;//�Ӽ����
	DWORD dwDisposition;
	RegCreateKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0,
		NULL, 0, KEY_ALL_ACCESS, NULL, &hroot, &dwDisposition);
	RegDeleteValue(hroot, "AutoRun");//ɾ���Ӽ�����ΪAutoRun�ļ�ֵ
	return 0;
}


����ʮ����RegQueryValueEx�����Ӽ������ȡһ����ֵ���ݣ����͡�


�������壺LONG
RegQueryValueEx(
	HKEY hKey,//�������
	LPCWSTR lpValueName,//��ֵ����
	LPDWORD lpReserved,//Ԥ������0
	LPDWORD lpType,//���ռ�ֵ����
	LPBYTE lpData,//���ռ�ֵ����
	LPDWORD lpcbData//�������ݵĴ�С
);


���ӣ���ȡRegSetValueEx���������ļ�ֵ�����ͣ�����


#include<windows.h>
#include<stdio.h>
int main()
{
	char Data[52];
	DWORD Size, Type;
	HKEY hroot;//�Ӽ����
	DWORD dwDisposition;
	RegCreateKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0,
		NULL, 0, KEY_ALL_ACCESS, NULL, &hroot, &dwDisposition);//��ȡ�������
	RegQueryValueEx(hroot, "AutoRun", 0, &Type, (BYTE*)Data, &Size);//��ȡAutoRun����Ϣ
	printf("��ֵ���ƣ�AutoRun ");
	switch (Type)
	{
	case REG_SZ:printf("��ֵ���ͣ�REG_SZ"); break;
	case REG_BINARY:printf("��ֵ����:REG_BINARY"); break;
	case REG_DWORD:printf("��ֵ����:REG_DWORD"); break;
	case REG_MULTI_SZ:printf("��ֵ����:REG_MULTI_SZ"); break;
	case REG_EXPAND_SZ:printf("��ֵ����:REG_EXPAND"); break;
	}
	printf(" ��ֵ���ݣ�%s %d\n", Data, Size);
	return 0;
}


����ʮ�߸�RegEnumValue�����Ӽ�������ض�Ӧ�����ļ�ֵ��Ϣ�����ƣ����ݣ����ͣ��Ӽ��µ�һ����ֵ����Ϊ0���Դ����ƣ������ɹ�ִ�з���ERROR_SUCCESS��


�������壺LONG
RegEnumValue(
	HKEY hKey,//�Ӽ����
	DWORD dwIndex,//��ֵ����
	LPWSTR lpValueName,//���ռ�ֵ���ƣ��ַ�����
	LPDWORD lpcbValueName,//ָ�������С
	LPDWORD lpReserved,//Ԥ����0
	LPDWORD lpType,//��ֵ���ͣ���NULL������ȡ
	LPBYTE lpData,//��ֵ���ݣ���NULL������ȡ
	LPDWORD lpcbData//�������ݵĴ�С�������ֵ�����������ΪNULL�������ҲΪNULL
);


���ӣ����Run�µ����м�ֵ��


#include<windows.h>
#include<stdio.h>
int main()
{
	char Name[52];
	int Index = 0;
	DWORD dwSize = 52;
	DWORD Size, Type;
	HKEY hroot;//�Ӽ����
	DWORD dwDisposition;
	RegCreateKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0,
		NULL, 0, KEY_ALL_ACCESS, NULL, &hroot, &dwDisposition);//��ȡ�������
	while (RegEnumValue(hroot, Index, Name, &dwSize, NULL, NULL, NULL, NULL) == ERROR_SUCCESS)
	{
		printf("%s\n", Name);
		Index++;//������0��ʼÿ������һ���������ִ��ʧ�ܣ��������ѵ�ͷ
	}
	return 0;
}


��ʵҲ����������һ�£�������msconfig���������г���ǰ����������п������������򣬵�Ȼ��ע���Ҳ��ֻ��ǰ�����һ���Ӽ��¿������������������HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run��Ҳ������ӣ�������Щ�Ӽ�����Ҫȥ�鿴���������������������Ӽ����Ե��ٶ���ȥ��һ�£�����������ǰ���Ǽ���ע���������������Խ������������һ��������ӣ��鿴��ɾ�����������������С����


����ʮ�˸�ExitWindowsEx�ػ���������ע�����������


�������ֻ��������������һ������ΪϵͳԤ������0�Ϳ����ˣ�����һ��������ָ���ػ���������������ע������ѡֵ���£�


EWX_LOGOFF//ע�� EWX_REBOOT//���� NTϵͳ����SE_SHUTDOWN_NAME ��Ȩ EWX_SHUTDOWN//�ػ�����Ȩ�ޡ�


���ӣ��رռ������������ҪSE_SHUTDOWN_NAMEȨ�ޣ��������ǵ�������Ȩ�ޣ��������£�


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


����ʮ�Ÿ�VirtualAllocEx�������Ľ����з����ڴ�ռ�


�������壺LPVOID
VirtualAllocEx(
	HANDLE hProcess,//���̾���������ڸý��̾����صĽ��̷���ռ�
	LPVOID lpAddress,//Ĭ��Ϊϵͳָ������NUL
	DWORD dwSize,//��������ڴ�
	DWORD flAllocationType,//��MEM_COMMIT
	DWORD flProtect//ָ��������ڴ����ԣ�ΪPAGE_READWRITE���ڴ�ɶ�д
);


�������ط�����ڴ��׵�ַ��


����ʮ��CreateRemoteThread����һ��Զ���̣߳������������д����̣߳�


�������壺HANDLE
WINAPI
CreateRemoteThread(HANDLE hProcess,//���̾������������������̾�������Ľ��̴����߳�


	LPSECURITY_ATTRIBUTES lpThreadAttributes,


	DWORD dwStackSize,
	LPTHREAD_START_ROUTINE lpStartAddress,
	LPVOID lpParameter,
	DWORD dwCreationFlags,
	LPDWORD lpThreadId
);


���������CreateThread��������һ��������������������ĵ�һ��hProcess�������ڸý����ﴴ���̣߳����������������������ʮ�Ÿ�����CreateThread����������һ��������Ͳ��ٽ����ˡ�


���ӣ�Զ���߳�ע��


����һ��Զ���̣߳��ͱ������һ���̺߳������߳�ִ�У����̺߳����ֲ����������������Ҫ��ô���أ���ҿ�һ���̺߳����Ķ��壬��LoadLibrary�����Ķ��壬���ǵĶ������ƣ�����ֻ��һ������������ÿ�������ܵ���LoadLibrary�������������Ǳ��ܰ�LoadLibrary������Ϊ�̺߳����������������߳̾ͻ�ȥִ��LoadLibrary������������Ǿ�����һ���������������LoadLibrar�����Ļ��ᣬ��������ָ��LoadLibrary�����Ĳ�����ͨ������Զ���̺߳������ݣ���ǰ���ڶ�̬���ӿ��ᵽ��һ�������������LoadLibrary�������������Զ�ȥִ����Ӧ��̬���ӿ����DllMain���������������Լ����Ա�дһ����̬���ӿ⣬��DllMain������д����Ҫ��������ִ�еĴ��롣��ͨ��CreateRemoteThread�������������򴴽�һ���߳�ȥִ��LoadLibary���������Ѿ���д�õĶ�̬���ӿ⣬�����Ϳ�������������ִ�����ǵĴ����ˡ����ﻹ��һ�����⣬CreateRemoteThread�������ݹ�ȥ�Ĳ�������ΪҪ��ע����Ǹ�������ʣ����Բ����������洢�Ŀռ䲻���ڵ���CreateRemoteThread�����ĳ�����������VirtualAllocEx��������ע����������һ���ռ䣬�����ݣ���̬���ӿ�����ƣ��������棬���·���ռ���׵�ַ����ΪCreateRemoteThread�����Ĳ�������ȥ������ע�������ʵ����Լ��ĵ�ַ�ռ䡣


Զ���߳�ע�룺


���趯̬���ӿ�Ϊ��ReCode.dll�����Ĵ������£�


#include<windows.h>
BOOL APIENTRY DllMain(HANDLE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved
)//DllMain������ֻҪ���������̬���ӿ�ĳ��򣬶�������ִ���������
{//������������������ִ�еĴ���
	while (1)
	{
		MessageBox(NULL, "aaaa", "aaaa", MB_OK);//�򵥵�����������ÿ��3�뵯��һ����ʾ��
		Sleep(3000);
	}
	return TRUE;
}


�������У�Ȼ������ɵġ�ReCode.dll���ļ����Ƶ�c:\\windows\\system23��ȥ��


ע���̵߳Ĵ��룺


//ѡ��ctfmon.exe�����뷨������Ϊ����Ҫע����̵߳ĳ���
#include<windows.h>
#include<tlhelp32.h>
#include<stdio.h>
int main()
{
	char DllName[25] = "ReCode.dll";
	HANDLE hProcess;//���ڴ洢ctfmon.exe�Ľ��̾��
	//����������Ȩ�ޣ�ʹ���ܻ�ȡ�κν��̾������������в���
	HANDLE hToken;
	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);
	TOKEN_PRIVILEGES tp;
	LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
	tp.PrivilegeCount = 1;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), NULL, NULL);
	////////////////////////////////////////////////////////////////////////////
	//Process32First��Process32Next������ϣ�Ѱ�ң���ȡctfmon.exe����ID��
	//�ٵ���OpenProcess�������ݽ���ID��ý��̾��
	PROCESSENTRY32 pe32;//���������Ϣ�洢����ṹ��
	pe32.dwSize = sizeof(pe32);
	//��ϵͳ�ڵ����н�����һ������
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
	while (bMore)
	{
		if (strcmp("ctfmon.exe", pe32.szExeFile) == 0)//����ҵ�������Ϊctfmon.exe
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);//��ȡ���
		bMore = ::Process32Next(hProcessSnap, &pe32);//Ѱ����һ��
	}


	//��ctfmon�����з���ռ�
	LPVOID lpBuf = VirtualAllocEx(hProcess, NULL, strlen(DllName), MEM_COMMIT, PAGE_READWRITE);
	DWORD WrSize;
	//��DllName�������д�뵽����Ŀռ���
	WriteProcessMemory(hProcess, lpBuf, (LPVOID)DllName, strlen(DllName), &WrSize);
	//����Զ���߳�
	CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, lpBuf, 0, NULL);
	return 0;//����ʹ����ɣ�����
}


��Ȼ, ��һ������װ����, Ҳ������ָ����Ӧ�ó�������ض��Ķ�̬���ӿ�, ��Ҫ�˽�, ���ض�̬���ӿ������Ӧ�ó����������, ���ܲ�����Ӧ�ó��򲻸����Լ�����, ����һֱִ��DllMain������Ĵ����!���Ҽ�ʹ����, ����װ���ӵĳ����˳���ж�ع��ӵ�ʱ����ô��ϵͳǿ�ȼ��ض�̬���ӿ�ĳ���Ҳ���Զ��ͷŶ�̬���⣬�˳�DllMain��������ˣ��Ǿ�û�а취���𣿣��취�϶����еģ���CreateThread�������������������߳�ִ��DllMain������ʱ��ʹ�����CreateThread�ٴ���һ���̣߳������ˡ�





http://hi.baidu.com/3582077/item/8d80115206f504968c12ed19


����ʮһ��GetWindowThreadProcessId���ݴ��ھ����ö�Ӧ����ID��, ���߳�ID��


����ֻ��������������һ�������Ǵ��ھ�����ڶ���������һ��DOWRD���͵�ָ��(����ID��, ���������߳�ID


	�� :


DWORD ThreadId, ProcessId;


ThreadId = GetWindowThreadProcessId(wnd, &ProcessId);


����ʮ����EnumWindowsö�ٵ�ǰ�����е����������ڣ��������Ӵ���


������������������붨��һ���ص����������ĸ�ʽ�������ģ�BOOL CALLBACK lpEnumFunc(HWNDwnd, LPARAM lParam);


EnumWindows������������������һ�����ǻص������ĵ�ַ����һ�����Զ����������Ӧ�Żص������ĵڶ���������


ÿö��һ�δ��ڣ�����ص������ͻᱻִ��һ�Σ�����õĴ��ھ�����ͻᴫ�ݸ��ص���������Ӧ�Żص������ĵ�һ��������ֱ��ö�������д��ڡ����ڻص��ú�����������ʾ����ö�٣����ؼ���ֹͣö�١�


���ӣ�ö�ٴ���


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
	GetWindowText(wnd, WindowName, sizeof(WindowName));//���ݴ��ھ����ô�����
	printf("���ھ��:%d ��������:%s\n,", wnd, WindowName);


	//����������Ӹ��жϵ�ǰ�Ƿ���һ��������������


	//��if(strcmp(WindowName,"Windows���������")==0) return 0;����ö�٣�
	return 1;
}


����ʮ����MessageBox����һ����Ϣ��ʾ��


int
MessageBox(
	HWND hWnd,//ָ����Ϣ���������ĸ����ڵģ�����ΪNULL
	LPCSTR lpText,//��Ϣ��ʾ��������
	LPCSTR lpCaption,//��ʾ�򴰿ڱ���
	UINT uType);//ָ����ʾ�����ͣ���ť��ͼ��
����ֻ˵��uType�ĳ��ÿ�ѡֵ��
��ť��
MB_ABORTRETRYIGNORE ��ֹ ���� ����
MB_OK ȷ��
MB_OKCANCEL ȷ�� ȡ��
MB_RETRYCANCEL ���� ȡ��
MB_YESNO �� ��
MB_YESNOCANCEL �� �� ȡ��
ͼ�꣺
MB_ICONWARNING ��̾��
MB_ICONINFORMATION ��ʾi
MB_ICONQUESTION �ʺ�
MB_ICONSTOP ��X��
��ť��ͼ����Խ���ã��磺
MessageBox(NULL, "���ڴ治�ܷ���", "����", MB_OK | MB_ICONSTOP);


ϵͳģʽ��MB_SYSTEMMODAL
�����ķ���ֵȷ���û�ѡ�����ĸ���ť�����������ť�Ķ��壺
IDABORT ����������ť
IDCANCEL ��ȡ������ť
IDIGNORE �����ԡ���ť
IDNO ���񡱰�ť
IDOK ȷ��
IDRETRY ����
IDYES ��
�жϷ���ֵ�Ƿ�������ȼ��ɡ�


����ʮ�ĸ�GetForegroundWindow��õ�ǰ����Ĵ��ھ��


����û���������ü�������ǰ���ھ��


�����һ�����ӣ�ÿ���л����ڵ�ʱ�򵯳�һ����Ϣ��ʾ��


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
			MessageBox(NULL, WindowName, "�л����ڵ�", MB_OK);
			Orgwnd = wnd;
		}
		Sleep(200);
	}
}


����ʮ���GetTopWindow���ݴ��ھ��������µ�һ�Ӵ��ھ��������У�


�ù�MFC���˶�֪�����ڶԻ��༭�������ҪΪ�ؼ�����Ļ����Ͱ�CTRL + D��ʾ��ÿ���ؼ���˳������ͼ��




��GetTopWindow������ȡ�ľ��ǿؼ�˳��Ϊ1�Ĵ��ھ����


���ӣ��ı�һ���������µĵ�һ�Ӵ��ڵ���ʾ���ݣ�ǰ������У���������������Ǹ�abc�Ի���Ϊ����


#include<windows.h>
int main()
{
	HWND wnd;
	wnd = FindWindow(NULL, "abc");
	HWND FirstWnd = GetTopWindow(wnd);
	SetWindowText(FirstWnd, "first");
	return 0;


}


ִ��Ч����


����ʮ����GetNextWindow�����Ӵ��ھ�������һ������һ��ͬ���Ĵ��ھ��������NULL������ִ��ʧ�ܣ�


������������������һ�����Ӵ��ھ�����ڶ�������ָ��Ѱ����һ��������һ�¸����ھ����ֵ��GW_HWNONEXT����һ������GW_HWNDPREV����һ�����������Ӵ��ھ���������ڵ�˳��Ϊ3����ô��ȡ����˳��Ϊ2��˳��Ϊ3�Ĵ��ھ��������ȡ���ڵڶ������������������ػ�õĴ��ھ��.����GetNextWindow���GetTopWindow�����Ϳ��Ա���һ����������������Ӵ����ˡ�


���ӣ�����һ��������������Ӵ��ڣ��������abc����Ϊ��


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
		printf("���ھ��:%d,����:%s\n", wnd, Name);
		wnd = GetNextWindow(wnd, GW_HWNDNEXT);//GW_HWNDNEXT��ȡ��һ��
	}
	return 0;
}


����ʮ�߸�InvalidateRect����һ��WM_PAINT��Ϣ�����ڣ�ˢ�´��ڣ�


�������壺BOOL
InvalidateRect(
	HWND hWnd,//Ҫˢ�´��ڵľ��
	CONST RECT *lpRect,//ˢ�µķ�Χ
	BOOL bErase//�ػ�ΪTRUE


);


���ӣ���SetTimer����������


����ʮ�˸�SetTimer����һ����ʱ����ÿ��һ��ʱ��ִ��һ�ζ�ʱ��������


�������壺UINT
SetTimer(
	HWND hWnd,//���ھ��
	UINT nIDEvent,//��ʱ��ID�ţ�Ϊ�������ö����ʱ��
	UINT uElapse,//ʱ�䣬ָ��������ִ��һ�ζ�ʱ����������λ������
	TIMERPROC lpTimerFunc);//��ʱ���ص������ĵ�ַ


��ʱ�������Ĺ̶���ʽ��VOID CALLBACK TimerProc(HWND hwnd, UINTuMsg, UINT_PTR idEvent, DWORD dwTime);


���ӣ�����w, a, s, d������һ�������ƶ���ͬʱ��һ����ͬ�ľ����Զ��ƶ���


#include<windows.h>
LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);//��������
VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{


	WNDCLASS wndcls; //����һ���洢������ϢWNDCLASS����
	wndcls.cbClsExtra = 0; //Ĭ��Ϊ0
	wndcls.cbWndExtra = 0; //Ĭ��Ϊ0
	wndcls.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); //������ˢ
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW); //���
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR); //����ͼ��
	wndcls.hInstance = hInstance; //Ӧ�ó���ʵ�������WinMain���������� 
	wndcls.lpfnWndProc = WinSunProc; //������Ϣ������
	wndcls.lpszClassName = "windowclass"; //��������
	wndcls.lpszMenuName = NULL; //���ڲ˵�����û�в˵���ΪNULL
	wndcls.style = CS_HREDRAW | CS_VREDRAW;//�������ͣ�CS_HREDRAW��CS_VERDRAW ����
	//������ˮƽ����ֱ����Ŀ�ȱ仯ʱ�ػ���������
	RegisterClass(&wndcls); //�Ѵ�����Ϣ�ύ��ϵͳ��ע�ᴰ����
	HWND hwnd; //���Դ洢CreateWindow�����������Ĵ��ھ��
	hwnd = CreateWindow("windowclass", "first windows",
		WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);//��������
	ShowWindow(hwnd, SW_SHOWNORMAL);//���ڴ������ˣ���ʾ��
	UpdateWindow(hwnd); //���´��ڣ��ô��ں����ӳٵ���ʾ
	SetTimer(hwnd, 1, 200, (TIMERPROC)TimerProc);//���ö�ʱ��
	MSG msg;//��Ϣ�ṹ����
	while (GetMessage(&msg, NULL, 0, 0))//��ȡ��Ϣ
	{
		TranslateMessage(&msg); //�˺������ڰѼ�����Ϣ(WM_KEYDOWN,WM_KEYUP)ת�����ַ���ϢWM_CHAR
		DispatchMessage(&msg); //����������ô��ڹ��̴�����������MSG�����Ϣ����󴫸����̺������ĸ�����
	}
	return 0;
}
VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)//��ʱ������
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
		::InvalidateRect(hwnd, &rect, TRUE);//����WM_PAINT��Ϣ��ˢ�´���
	}
	break;
	case WM_PAINT:
		HDC dc;
		PAINTSTRUCT ps;
		dc = BeginPaint(hwnd, &ps); //BeginPaintֻ������ӦWM_PAINT,������GetDC��ȡ�豸������
		Rectangle(dc, x, y, x + 30, y + 30);
		break;
	case WM_CLOSE://�û��ر��˴���
		DestroyWindow(hwnd);//���ٴ��ڣ�������WM_DESTROY��Ϣ
		break;
	case WM_DESTROY://������ڱ�����
		PostQuitMessage(0);//�ý����˳�
		break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam); //δ�������Ϣͨ��DefWindowProc��������ϵͳ����
}


����ʮ�Ÿ�RegisterHotKeyע��һ���ȼ�


�������壺BOOL
RegisterHotKey(
	HWND hWnd,
	int id,
	UINT fsModifiers,
	UINT vk);


��һ������hWnd�����ȼ���Ϣ��HOT_KEY�����͸��ĸ����ڣ�ΪNULL����ֱ�Ӱ���ϢͶ�ݸ���������������̵���Ϣ���С�


�ڶ������������Զ�ȡֵ��ȡֵ��Χ0xC000 - 0xFFFF, ���������Ϊ�˳�����ͬʱӵ�ж���ȼ������ڡ�


����������fsModifiers�Ŀ�ѡȡֵ���£�MOD_ALT��Alt������MOD_CONTROL��Ctrl������MOD_SHIFT��Shift������MOD_WIN�����ͼ�����
��һ��������һ��ASCIIֵ��ָ��������ĸ���ϵͳ����ϡ�
��QQ���ȼ�ctrl + alt + z��ע������ȼ��������RegisterHotKey(NULL, 0x0001, MOD_CONTROL | MOD_ALT, ��Z��)
��QQ�Ľ�ͼ�ȼ�RegisterHotKey(NULL, 0x0001, MOD_CONTROL | MOD_ALT, 'A')


���ӣ�����ctrl + alt + x�ȼ���������Ϣ��ʾ��ѯ���Ƿ�Ҫ�˳���


//#include "stdafx.h" �½��չ��̣�����Ҫ��ͷ�ļ�
#include<windows.h>
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	RegisterHotKey(NULL, 0x0001, MOD_CONTROL | MOD_ALT, 'X');//ע���ȼ�
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))//����Ϣ�����ȡ��Ϣ
	{
		if (msg.message == WM_HOTKEY)//�ȼ���Ϣ
		{
			if (MessageBox(NULL, "��ȷ��Ҫ�˳�������", "�ȼ���ʾ", MB_YESNO | MB_SYSTEMMODAL) == IDYES)
			{
				UnregisterHotKey(NULL, 0x0001);//ж���ȼ�
				break;
			}
		}
	}
	return 0;
}


�ǵ�Ҫ�˳�����


����ʮ��StretchBlt�ڴ������һ��λͼ


���������BitBlt���������������Ǿ���ԴĿ��DC�Ŀ�ߣ���BitBlt������ֻ��Ŀ��DC�Ŀ�ߡ�


���������������ļ��룬StretchBlt�������ܾͱ�BitBlt����ǿ������࣬��������С��Ŵ�ͼƬ�����԰�һ��ͼƬ�ϵ�����������򸲸ǵ���һ��ͼƬ�ϵ���������


������䣺StretchBlt(hdc, 0, 0, bmInfo.bmWidth, bmInfo.bmHeight, memDC, 0, 0, 50, 50, SRCCOPY);


�����÷��ο�BitBlt������


���ӣ��ڴ��������������״��λͼ��


˵����


λͼ��ʵ���Ǿ��Σ�����Ҫ˵���ǿ������λͼ���������״���֣���λͼ������Ĳ��֣������ǹ̶�����ɫ


Ϊʲô�أ���ɫ��RGBֵ��255��255��255����255ת���ɶ����ƣ����Կ���ÿһλ����1���磺11111111.�����κ�һ����ɫ���ɫ���а�λ�����㣬����������䣬��������DC�ϲ����а�λ�루SRCAND�����㣬��ɫ�Ĳ��ֶ��ᱻ���Σ����κ�һ����ɫ���ɫ���а�λ�����㣬������Ϊ��ɫ�����ɫ���а�λ��SRCAND�����㣬��������ı䡣��ɫ��RGBֵ��0��0��0��


���������ͼ�Σ�Ҫ׼������ͼƬ������������ģʽ�����£�


flower1 flower2


����Ҫ����ڴ��������flower2ͼƬ��Ļ�����ɫ���ֲ����


����������ͼƬ��E�̣������ӣ�


#include<windows.h>
int main()
{
	HWND wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");


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
			0, 0, bmInfo.bmWidth, bmInfo.bmHeight, SRCAND);//��λ������ϲ�DC
		SelectObject(memDC, hBmp2);
		StretchBlt(dc, 0, 0, bmInfo.bmWidth, bmInfo.bmHeight, memDC,
			0, 0, bmInfo.bmWidth, bmInfo.bmHeight, SRCPAINT);//��λ������ϲ�DC
		Sleep(200);
	}


}


����Ч������ͼ��








http://hi.baidu.com/3582077/item/5668f7ef963711d3ea34c919


����ʮһ��TextOut�����豸DC�ڴ����������


�������� : BOOL TextOut(HDC hdc,// �豸DC
	int nXStart,// ����x����
	int nYStart,// ����y���꣬�ַ������Ͻ��ǽ���x,y
	LPCTSTR lpString,// �ַ���
	int cbString// �ַ������ַ��ĸ���
);


���ӣ��ڴ���������֣�Ϊ�˷��㣬����������"�ޱ���.txt - ���±�", �������������


#include<windows.h>
#include<string.h>
int main()
{
	char Text[52] = "�������50,50��ʼ�������";
	HWND wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
	HDC dc = GetDC(wnd);
	SetTextColor(dc, RGB(255, 0, 0));//����������ɫ
	while (1)
	{
		TextOut(dc, 50, 50, Text, strlen(Text));
		Sleep(200);
	}
	return 0;
}


����ʮ����DrawText�����豸DC�ڴ��ڵ�һ��������������֡�
int
DrawTextW(
	HDC hDC,//�豸DC
	LPCWSTR lpString,//�ַ���
	int nCount,//�ַ����ĸ���
	LPRECT lpRect,//ָ��һ��������
	UINT uFormat);//�����ʽ


uFormat�ĳ���ȡֵ


ֵ ˵��
DT_BOTTOM �����ĵ��������εײ�����ֵ�����DT_SINGLELINE��ϡ�
DT_CENTER ʹ�����ھ�����ˮƽ���С�
DT_VCENTER ʹ�����ھ����д�ֱ���С�
DT_END_ELLIPSIS ������ʾ���ı�������������ַ����ķ�Χ���ھ����ڣ����ᱻ�ضϲ���ʡ�Ժű�ʶ��
���һ����ĸ�������ַ�����ĩβ�������˾��η�Χ�������ᱻ�ضϲ���ʡ�Ժű�ʶ��
�ַ������ᱻ�޸ģ�����ָ����DT_MODIFYSTRING��־��
T_WORD_ELLIPSIS, DT_PATH_ELLIPSIS��DT_END_ELLIPSIS���ܺʹ˲���һ��ʹ��
DT_LEFT ��������롣
T_RIGHT �����Ҷ��롣
DT_RTLREADING ��ѡ����豸������������ϣ�����Ļ�����������ʱ��Ϊ˫�����İ��Ŵ��ҵ�����Ķ�˳���Ǵ����ҵġ�
DT_TOP ���Ķ��˶��루���Ե��У���
DT_WORDBREAK �Ͽ��֡���һ���е��ַ��������쵽��lpRectָ���ľ��εı߿�ʱ�������Զ�������֮��Ͽ���һ���س�һ����Ҳ��ʹ���۶ϡ�
DT_WORD_ELLIPSIS �ض̲����Ͼ��ε����ģ�������ʡ�Ժš�


����ʮ����GetLogicalDriveStrings��ȡϵͳ������Ϣ


�������壺DWORD
GetLogicalDriveStrings(
	DWORD nBufferLength,//ָ��lpBuffer������С
	LPSTR lpBuffer//������Ϣ����洢�������������ʽ�ǡ�����NULL����NULL����NULLNULL������NULL��β


	//���赱ǰ������C��D��E���������ַ����Ĵ洢��ʽ��"C:\\\0D:\\\0E:\\\0\0"; ('\\'ת���ַ�\)
);


���ӣ�ö�ٵ�ǰ�������з���


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


����ʮ�ĸ�GetDiskFreeSpaceEx��ȡһ���������̷�������Ϣ�����ÿռ䣬�ܴ�С�����ÿռ䣩


�������������ULARGE_INTEGER�����������洢����ʹ����Ϣ����ΪҪ��ȡ���̵����ÿռ䣬�ܴ�С�����ÿռ䣬�������Ǳ��붨������ULARGE_INTEGER���ͱ������洢��������Ϣ����������Ϣ�ʹ洢��ULARGE_INTEGER���͵�QuadPart��Ա�������ó�Առ��λ�ֽڣ�


���ȡC�̵���Ϣ��ULARGE_INTEGERdwAvailable, dwFree, dwTotal;


GetDiskFreeSpaceEx("c:\\", &dwAvailable, &dwTotal, &dwFree);//��ȡ������Ϣ


������GetLogicalDriveStrings�ٸ����ӣ���ȡ��ǰ�������з�����Ϣ�����


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
	GetDiskFreeSpaceEx(Par, &dwAvailable, &dwTotal, &dwFree);//��ȡ������Ϣ
	Size = dwTotal.QuadPart / 1024 / 1024;//��ȡ�ܴ�С
	fDwt = Size / 1024.0;
	Size = dwAvailable.QuadPart / 1024 / 1024;//��ȡ���ÿռ�
	fDwa = Size / 1024.0;
	Size = dwFree.QuadPart / 1024 / 1024;//��ȡ���ÿռ�
	fDwf = Size / 1024.0;
	sprintf(szSize, "�ܴ�С:%0.2fGB ���ÿռ�:%0.2fGB ���ÿռ�:%0.2fGB", fDwt, fDwa, fDwf);
	printf("%s\n", szSize);
	return 0;
}


����ʮ���WritePrivateProfileString�޸Ļ򴴽�һ��INI�ļ��������


INI�ļ�������һ���ɽ�������������ֵ��ɣ�������һ��INI�ļ��Ľṹ����һ��INI�ļ�, ���ǿ��ܻῴ����������


////////////////////////////////////////////////////////////////////////////////////


[gmy_p]
exist_p = 0
linux_p =


[boot]
a20 = 0
a21 = 0


///////////////////////////////////////////////////////////////////////////////////


�����������[gmy_p]��[boot]����INI�ļ��Ľ��������������������ͼ�ֵ��һ��INI�ļ������ж������.


��ô��Щ�Ǽ�������Щ�Ǽ�ֵ�أ��ڡ� = ����ߵ��Ǽ����������ұߵľ��Ǽ�ֵ����ֵ����ΪNULL��


���ˣ���һ��WritePrivateProfileString�ĺ����Ķ��壺


BOOL
WritePrivateProfileString(
	LPCWSTR lpAppName,//����
	LPCWSTR lpKeyName,//����
	LPCWSTR lpString,//�޸ĵ�����
	LPCWSTR lpFileName//INI�ļ���
);


���Ҫ�޸ļ�ֵ����ôҪ�ṩ��Щ��Ϣ�أ����ȣ�����Ҫ֪��INI�ļ���·����lpFileName)��Ҫ�޸ĵļ�ֵ�����ĸ�������(lpAppName)���Լ��������ĸ�����(lpKeyName)�������޸ĵļ�ֵ����(lpString).


������Ҫ��֮ǰINI�ļ������Ϊgmy_p�µļ���exist_p�ļ�ֵ��Ϊ100(��������ļ���·��Ϊd:\gho.ini).


��ô������䣺WritePrivateProfileString("gmy_p", "exist_p", "100", "d:\\gho.ini");


WritePrivateProfileString�������ܲ�ֹ�ڴˣ��������ṩ��INI�ļ���������������������ʱ����ô�����ͻᴴ�����ǡ����������ǾͿ����������������һ��INI�ļ�������һ��INI�ļ��ﴴ��һ������������һ�������´���һ��������


�磺WritePrivateProfileString("ZhengYong", "QQ", "***980073", "d:\\Info.ini");


����ʮ����GetPrivateProfileString��ȡһ��INI�ļ��������


�������壺DWORD
GetPrivateProfileStringW(
	LPCWSTR lpAppName,//����
	LPCWSTR lpKeyName,//����
	LPCWSTR lpDefault,//Ĭ��ֵ����0�ȿ�
	LPWSTR lpReturnedString,//�������ݵĻ��������ַ�����
	DWORD nSize,//ָ���������Ĵ�С
	LPCWSTR lpFileName//INI�ļ���
);


���ӻ�ȡһ����ֵ������D������һ����ΪInfo.ini�ļ��������������£�


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


�������Ҫ��ȡ����Ϊ"ZhengYong"�µļ���QQ�ļ�ֵ����ô���ǣ�


#include<windows.h>
#include<stdio.h>
int main()
{
	char KeyValue[252];
	::GetPrivateProfileString("ZhengYong", "QQ", 0, KeyValue, 252, "d:\\Info.ini");
	printf("%s\n", KeyValue);
	return 0;
}


ͬWritePrivateProfileString���ƣ�����ṩ�Ľ����������ΪNULL�����ȡ��ǰ���еĽ������������������Ϣ�洢��ʽһ�����ַ��������������������'\0'������ַ�������������'\0'������


���ӣ�ö��ZhengYong�����µ����м�����


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


��ôö�ٽ���ֻҪ������������У��Ѻ����Ľ���������ΪNULL�����ˣ��磺


GetPrivateProfileString(NULL, NULL, 0, Data, 252, "d:\\Info.ini");


��ҿ��������������һ����ȡINI�ļ����ݵĳ����Ա���õ���������������ǵðѽ������ݵĻ��������ô�һ�㡣


����ʮ�߸�GetSystemMetrics����ض����ڵĸ߿��


�ú���ֻ��һ������������ȡֵ���£�


SM_CXSCREEN ��Ļ���


SM_CYSCREEN��Ļ�߶�


SM_CXFULLSCREEN���ڿͻ������


SM_CYFULLSCREEN���ڿͻ����߶�


SM_CYMENU�˵����߶�


SM_CYCAPTION//�������߶�


SM_CXBORDER���ڱ߿���


SM_CYBORDER���ڱ߿�߶�


SM_CXSIZE �������ϵİ�ť���
SM_CYSIZE �������ϵİ�ť�߶�


���ӣ���ȡ��Ļ�ֱ��ʣ������߶ȣ�


#include<windows.h>
#include<stdio.h>
int main()
{
	int ScreenX = ::GetSystemMetrics(SM_CXSCREEN);
	int ScreenY = ::GetSystemMetrics(SM_CYSCREEN);
	printf("��Ļ�ֱ���:%dX%d\n", ScreenX, ScreenY);
	return 0;
}


����ʮ�˸�SetWindowPos����һ�����ڵĴ�С������Z��


���ڵ�Z����ʲô��˼�أ��ù�MFC����Ӧ�ö�������ڶԻ���༭����CTRL + D�ͻ���ʾ��ÿ���ؼ���˳������ͼ��


���ÿؼ���˳����ʲô���أ���ҿ������������ؼ���ʲô�ر���𣿶��ˣ������ؼ�������һ�����ص�����ʱ����������ˣ��ص��Ĳ�����ʾ�����Ǹ������أ�����˵����ʲô��ȷ����ʾ�ĸ����ڣ�������ҲӦ�òµ��ˣ����Կؼ���˳����ȷ���ġ�˳��ϴ�Ļᱻ��ʾ�����������������ͼ��ʾ��


���״��ڵ�Z���ˣ����Ǿ�����һ����������Ĳ���������˼��


�������壺BOOL
SetWindowPos(
	HWND hWnd,//Ҫ���õĴ��ھ��
	HWND hWndInsertAfter,
	int X,
	int Y,//X,Yָ���������Ͻǵ�λ��
	int cx,//���ڿ��
	int cy,//���ڸ߶�
	UINT uFlags);


�ڶ�������hWndInsertAfter�ĳ���ȡֵ��


HWND_BOTTOM��
����������Z��ĵײ�.
HWND_NOTOPMOST�����������Z�򶥲�����ȡ������λ�ã�������ǣ���ò�����Ч
HWND_TOP : ����������Z��Ķ�����
	HWND_TOPMOST : ����������Z��Ķ��������ڵ�ǰδ�����Ҳ��Ȼ�Ƕ���λ��


	���һ������uFlags������Z����hWnd��ǰһ�����ھ���Ļ����³���ȡֵ��


	SWP_HIDEWINDOW; ���ش���


	SWP_SHOWWINDOW����ʾ����


	SWP_NOMOVEָ��X, Y������Ч


	SWP_NOSIZEָ��CX, CY������Ч


	SWP_NOZORDERָ��hWndInsertAfter������Ч


	���ӣ�����һ��������PPS��������������������ǰ��ʾ��


	��"�ޱ���.txt - ���±�"����Ϊ��


#include<windows.h>
	int main()
{
	HWND wnd = ::FindWindow(NULL, "�ޱ���.txt - ���±�");
	::SetWindowPos(wnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE);
	return 0;
}


����2��ȫ��һ������


������"�ޱ���.txt - ���±�"����Ϊ����


#include<windows.h>
int main()
{
	int ScreenX = ::GetSystemMetrics(SM_CXSCREEN);
	int ScreenY = ::GetSystemMetrics(SM_CYSCREEN);
	HWND wnd = ::FindWindow(NULL, "�ޱ���.txt - ���±�");
	::SetWindowPos(wnd, HWND_TOPMOST, 0, 0, ScreenX, ScreenY, SWP_SHOWWINDOW);
	return 0;
}


����ʮ�Ÿ�CreateFile����һ���ļ������һ���ļ����ڶ�д, ���������ļ����


�������壺HANDLE
CreateFile(
	LPCSTR lpFileName,//�ļ���
	DWORD dwDesiredAccess,//ָ�����ļ����к��ֲ�������Ҫ������GENERIC_READ������Ҫд�루GENERIC_WRITE��
	DWORD dwShareMode,//ָ���ļ�����ͬʱ����������д��FILE_SHARE_READ����ͬʱ����FILE_SHARE_WRITED����ͬʱд
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,//ָ��һ��SECURITY_ATTRIBUTES�ṹ��ָ�룬һ��ΪNULL


	DWORD dwCreationDisposition,//��ȫ���ԣ�ָ���Ժ��ַ�ʽ�򿪻򴴽��ļ�
	DWORD dwFlagsAndAttributes,//ָ���ļ������ԣ����أ�ֻ����ϵͳ�ļ���ΪNULL��ʾĬ������
	HANDLE hTemplateFile// �����Ϊ�㣬��ָ��һ���ļ���������ļ���������ļ��и�����չ����
);


���������dwCreationDisposition�ĳ���ȡֵ����˼


TRUNCATE_EXISTING �������ļ�����Ϊ�㳤�ȣ�����ļ������ݣ��ļ������Ѿ�����


CREATE_ALWAYS ����һ���ļ�������ļ��Ѿ����ڣ��򸲸���


CREATE_NEW �����ļ�������ļ��Ѿ����ڣ�����ִ��ʧ��


OPEN_ALWAYS���ļ�������ļ������ڣ��򴴽���


OPEN_EXISTING ���ļ����ļ�������ڡ�


����������dwFlagsAndAttributes�ĳ���ȡֵ������˼


FILE_ATTRIBUTE_NORMAL Ĭ������


FILE_ATTRIBUTE_HIDDEN ����


FILE_ATTRIBUTE_READONLY ֻ��


FILE_ATTRIBUTE_SYSTEM ϵͳ�ļ�


�ڰ�ʮ��ReadFile�����ļ���������ļ��ж�ȡһ������


�������壺BOOL
WINAPI
ReadFile(
	HANDLE hFile,//�ļ����
	LPVOID lpBuffer,//�����ļ����ݵĻ�����
	DWORD nNumberOfBytesToRead,//ָ����ȡ��������(�ֽڣ�
	LPDWORD lpNumberOfBytesRead,//ʵ�ʶ�ȡ����
	LPOVERLAPPED lpOverlapped// һ��ΪNULL�����ļ���ʱָ����FILE_FLAG_OVERLAPPED���òβ��о���ȡֵ��
);


���ӣ���ȡtxt�ļ������ݣ�����E������һ����a.txt���ļ����ļ�����Ϊ123456789


#include<windows.h>


#include<stdio.h>


int main()
{
	char Text[25] = { 0 };
	DWORD dwSize;
	HANDLEFileHandle = CreateFile("e:\\a.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING
		, FILE_ATTRIBUTE_NORMAL, NULL);//��ȡ�ļ����
	ReadFile(FileHandle, Text, 15, &dwSize, NULL);//���ļ��ж�ȡ15���ֽ�
	printf("���ݣ�%s ʵ�ʶ����ֽڣ�%d\n", Text, dwSize);
	return 0;
}





http://hi.baidu.com/3582077/item/5f4f58e718028fabc10d751b


�ڰ�ʮһ��WriteFile�����ļ������д��һ�����ݵ��ļ���


�������壺BOOL
WriteFile(
	HANDLE hFile,//�ļ����
	LPCVOID lpBuffer,//�û����������ݽ�Ҫд�뵽�ļ���
	DWORD nNumberOfBytesToWrite,//ָ��д���������
	LPDWORD lpNumberOfBytesWritten,//ʵ��д������
	LPOVERLAPPED lpOverlapped//һ��ΪNULL
);
���ӣ���E�̴���һ����Ϊaa.txt���ļ���������д������


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


�ڰ�ʮ����SetFilePointer�ƶ�һ���ļ�ָ���λ��


�ƶ�һ���ļ�ָ���λ����ʲô���أ������Ƕ�ȡһ���ļ���ָ��λ�õ����ݣ�������ֻҪ��ȡ�ļ��е��ĸ��ֽڵ����߸��ֽ���һ�ε����ݣ���SetFilePointer�����Ϳ�����ɡ�


�������壺DWORD
SetFilePointer(
	HANDLE hFile,//�ļ����
	LONG lDistanceToMove,//�ƶ��ֽڣ�������ʾ�����ƶ�
	PLONG lpDistanceToMoveHigh,//Ϊ��֧�ֳ����ļ������ڣ�һ��ΪNULL
	DWORD dwMoveMethod//�����￪ʼ�ƶ���FILE_BEGIN ���ļ���ʼ����ʼ�ƶ���FILE_CURRENT��ǰλ�ã�FILE_END�ļ�ĩβ
);


���ӣ�����E������һ����Ϊa.txt���ļ�������Ϊ"123456789", ��ȡ���ļ����ĸ��ֽڵ����߸��ֽڵ�����


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


����2�����ļ��е��ĸ��ֽڿ�ʼд�����ݣ�����������ռλ�õ����ݻᱻ���ǵ�������������a.txt�ļ�Ϊ����


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


��д���a.txt�ļ��������Ϊ123abcd89


���Ҫ���ļ���ĩβ������ݣ����������䣺SetFilePointer(FileHandle, 0, NULL, FILE_END);


�ڰ�ʮ����GetFileSize��ȡһ���ļ��Ĵ�С


�������壺DWORD
GetFileSize(
	HANDLE hFile,//�ļ����
	LPDWORD lpFileSizeHigh//һ��ΪNULL
);


���ȡa.txt�ļ��Ĵ�С��


#include<windows.h>


#include<stdio.h>


int main()
{
	DWORD FileSize;
	HANDLE FileHandle = CreateFile("e:\\a.txt", GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);
	FileSize = GetFileSize(FileHandle, NULL);
	printf("%d�ֽ�\n", FileSize);
	return 0;
}


�ڰ�ʮ�ĸ�SetTextColor���ô�������ı���ɫ


��һ���������豸DC���ڶ���������һ��COLORREF���͵���ɫֵ������RGB����ת����


�ڰ�ʮ���SetBkColor���ñ�����ɫ


������SetTextColor����һ������һ��DC���ڶ���COLORREF


�ڰ�ʮ����GetWindowDC��ȡ���������豸������DC


��GetDC��ȡ��ֻ�ǿͻ���DC�����ܶԴ��ڱ�������״̬���Ƚ��в������ú����÷���GetDCһ����������һ����


���ӣ���һ�����ڵı������������


#include<windows.h>


int main()


{


	HWND wnd = FindWindow(NULL, "�ޱ���.txt- ���±�");
	HDC dc = GetWindowDC(wnd);
	SetTextColor(dc, RGB(255, 0, 0));//�ı���ɫ����Ϊ��ɫ
	::SetBkColor(dc, RGB(0, 0, 255));//�ı�������ɫ����Ϊ��ɫ
	while (1)
	{
		TextOut(dc, 0, 0, "123456", 6);
		Sleep(200);
	}
	return 0;
}


�ڰ�ʮ�߸�GetDesktopWindow��ȡ���洰�ھ��


�ú���û�в��������÷������洰�ھ��


���ӣ�


#include<windows.h>
int main()
{
	HWND DeskWnd = GetDesktopWindow();//��ȡ���洰�ھ��
	HDC DeskDC = GetWindowDC(DeskWnd);//��ȡDC
	HBRUSH brush = ::CreateSolidBrush(RGB(255, 0, 0));//��ɫ��ˢ
	SelectObject(DeskDC, brush);//ѡ�뻭ˢ
	while (1)
	{
		::Rectangle(DeskDC, 50, 50, 200, 200);
		Sleep(200);
	}
	return 0;
}


�ڰ�ʮ�˸�CreateCompatibleBitmap����DC����һ�����ݵ�λͼ


�ú�������CreateCompatibleDC�������ʹ��


������һ�������Ǵ���DC���ڶ���������ָ�����ڿ�ߣ���������λͼ���(HBITMAP��


	����һ�����ݵ�λͼ��ʲô��˼�أ��ͺñȸ�HBITMAP�����ڴ��Լ�ָ����λͼ��ص�һЩ��Ϣ����DC��ص���Ϣ������λͼ�Ŀ�ߣ����ݴ�С������ʱ����û�о���ȡֵ���ͺñ�һ���ַ��������Ѿ�֪���ַ�����С�ˣ���ȴ��֪���ַ���������ʲô��


	�磺


	char *p;


p = new char[15];//֪���ַ�����СΪ15


����ʱp��ָ��Ļ�������û�о���ȡֵ��


����CreateCompatibleBitmap������������λͼ��ֻ��һ���տ��ӡ�����û�и�ֵ����Ҫ���������ݸ�ֵ�أ�


���ȵð����λͼ���ѡ��һ��DC����DC����ΪCreateCompatibleDC���������ģ��Ȼ������BitBlt������������ݸ�ֵ�����ˡ�


���ӣ�ʵʱ��ȡ��Ļͼ��


Ϊ�˷��㣬�ڼ��±��������ͼ���Լ��Ͳ����������ˣ���"�ޱ���.txt - ���±�")


#include<windows.h>
int main()
{
	HWND TextWnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
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


�ڰ�ʮ�Ÿ�GetDIBits��һ������λͼ���ȡλͼ����
��������һ��λͼ�ļ���Ϣ�ṹ��һ��λͼ�������Ĳ�����ɣ�


λͼ�ļ�ͷ��BITMAPFILEHEADER��//ռ14�ֽ�


λͼ��Ϣͷ��BITMAPINFOHEADER��//ռ40�ֽ�


��ɫ�壨LOGPALLETE��//��������λͼ���Ǹò���û�У�ֱ����λͼ����


ʵ��λͼ����


��GetDIBits������ȡ�ľ���ʵ��λͼ������һ�����ˡ�


������һ��BITMAPFILEHEADER����ṹ�Լ�����Ա����˼��ȡֵ


typedef struct tagBITMAPFILEHEADER {
	WORD bfType;//��ʾ�ļ����ͣ�ֵ����Ϊ0x4d42
	DWORD bfSize;//�ļ��Ĵ�С
	WORD bfReserved1;//����������Ϊ0
	WORD bfReserved2;//����������Ϊ0
	DWORD bfOffBits;//λͼǰ��������ռ���ֽڣ����ɫλͼΪ54
} BITMAPFILEHEADER;


����ĳ�Ա��ֻ��bfSize��ȡֵ��ȷ����������һ����Ҳ����˵��ÿ�����λͼ���⼸����Աȡֵ����һ����.��������ӿ���˵����


��ȡһ�����λͼ���ļ���Ϣͷ��


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


������һ��BITMAPINFOHEADER����ṹ�Լ�����Ա����˼��ȡֵ


typedef struct tagBITMAPINFOHEADER {
	DWORD biSize;//���ṹ��С��Ϊ40
	LONG biWidth;//λͼ�Ŀ�ȣ�������Ϊ��λ
	LONG biHeight;//λͼ�ĸ߶ȣ�������Ϊ��λ
	WORD biPlanes;//Ŀ���豸�ļ��𣬱�����1
	WORD biBitCount;//ÿ��������ռ��λ����24��ʾ���λͼ
	DWORD biCompression;//λͼѹ�����ͣ�һ��ΪBI_RGB��δ��ѹ����
	DWORD biSizeImage;//ʵ��λͼ������ռ�õ��ֽ���
	LONG biXPelsPerMeter;//ָ��Ŀ���豸ˮƽ�ֱ��ʣ���λ����/�ף�Ϊ0
	LONG biYPelsPerMeter;//ָ��Ŀ�괹ֱ�ֱ����棬��λ����/�ף�Ϊ0
	DWORD biClrUsed;//ָ��Ŀ���豸ʵ���õ�����ɫ���������ֵΪ0�����õ�����ɫ��Ϊ2��biBitCount��
	DWORD biClrImportant;//��ʾͼ������Ҫ����ɫ�������Ϊ0����������ɫ������Ҫ�ġ�
} BITMAPINFOHEADER;


��ɫ�壨LOGPALLETE�����ڴ󲿷ֶ���������λͼ�������˲����Թ�


GetDIBits�������壺int GetDIBits(


	HDC hdc, //λͼ���ݵ�DC


	HBITMAP hbmp, //λͼ���


	UINT uStartScan, //�����п�ʼɨ��


	UINT cScanLines, //ɨ�����������


	LPVOID lpvBits, //�������ݵĻ�����


	LPBITMAPINFO lpbi, //���λͼ���˴���λͼ��Ϣͷ������


	UINT uUsage//���λͼ��DIB_RGB_COLORS����ʾ��R,G,B��ɫֱ�ӹ���


);


���ӣ�������������ĻͼƬ�����λͼ


#include<windows.h>
void ScreenSnap(HBITMAP hBitmap, char *bmpPath, HDC dc);
int main()
{
	HWND DeskWnd = ::GetDesktopWindow();//��ȡ���洰�ھ��
	RECT DeskRC;
	::GetClientRect(DeskWnd, &DeskRC);//��ȡ���ڴ�С
	HDC DeskDC = GetDC(DeskWnd);//��ȡ����DC
	HBITMAP DeskBmp = ::CreateCompatibleBitmap(DeskDC, DeskRC.right, DeskRC.bottom);//����λͼ
	HDC memDC = ::CreateCompatibleDC(DeskDC);//����DC
	SelectObject(memDC, DeskBmp);//�Ѽ���λͼѡ�����DC��
	BitBlt(memDC, 0, 0, DeskRC.right, DeskRC.bottom, DeskDC, 0, 0, SRCCOPY);//����DC
	ScreenSnap(DeskBmp, "d:\\Screen.bmp", DeskDC);
	return 0;
}
void ScreenSnap(HBITMAP hBitmap, char *bmpPath, HDC dc)
{
	BITMAP bmInfo;
	DWORD bmDataSize;
	char *bmData;//λͼ����
	GetObject(hBitmap, sizeof(BITMAP), &bmInfo);//����λͼ�������ȡλͼ��Ϣ
	bmDataSize = bmInfo.bmWidthBytes*bmInfo.bmHeight;//����λͼ���ݴ�С
	bmData = new char[bmDataSize];//��������
	BITMAPFILEHEADER bfh;//λͼ�ļ�ͷ
	bfh.bfType = 0x4d42;
	bfh.bfSize = bmDataSize + 54;
	bfh.bfReserved1 = 0;
	bfh.bfReserved2 = 0;
	bfh.bfOffBits = 54;
	BITMAPINFOHEADER bih;//λͼ��Ϣͷ
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
	::GetDIBits(dc, hBitmap, 0, bmInfo.bmHeight, bmData, (BITMAPINFO*)&bih, DIB_RGB_COLORS);//��ȡλͼ���ݲ���
	HANDLE hFile = CreateFile(bmpPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, 0);//�����ļ�
	DWORD dwSize;
	WriteFile(hFile, (void *)&bfh, sizeof(BITMAPFILEHEADER), &dwSize, 0);//д��λͼ�ļ�ͷ
	WriteFile(hFile, (void *)&bih, sizeof(BITMAPINFOHEADER), &dwSize, 0);//д��λͼ��Ϣͷ
	WriteFile(hFile, (void *)bmData, bmDataSize, &dwSize, 0);//д��λͼ����
	::CloseHandle(hFile);//�ر��ļ����
}


�ھ�ʮ��FindWindowEx����һ������������Ӵ��ڣ������Ӵ����������������������������Ӵ��ھ��


�������壺HWND FindWindowEx


��HWND hwndParent,//�����ھ��


HWND hwndChildAfter,//�Ӵ��ھ����ָ��Z��


LPCTSTR lpszClass,//��������


LPCTSTR lpszWindow//��������


��;


��һ������hwndParent���ΪNULL���������洰��Ϊ�����ڣ���ʱ�����������FindWindow����һ��,


�ڶ����������Ӵ��ھ�������ΪNULL����������ڵĵ�һZ��ʼ���ң�����Ӹ��Ӵ��ڵ�Z��ʼ���ҡ�


����������������FindWindow������������˼һ����


���ӣ�ģ�°�ť����


����һ�����������ض��İ�ť��Ȼ����SendMessage�����������ڷ��Ͱ�ť����������Ϣ


���������������Ϊ"abc", ������һ����Ϊ"ȷ��"�İ�ť


��ʾ��


�ؼ���Ϣ�ǣ�WM_COMMAND��wParam������ʮ��λ�洢��ؼ�ID�ţ���ʮ��λ�洢�о���ؼ���Ϣ����BN_CLICKED����������lParam�洢�ؼ����ھ�����ؼ�ID�ſ�����GetDlgCtrlID������ȡ���ú������ݿؼ����ھ������ȡ�ؼ�ID�š�


#include<windows.h>
int main()
{
	HWND wnd = ::FindWindow(NULL, "abc");
	HWND ButtonWnd = ::FindWindowEx(wnd, NULL, NULL, "ȷ��");//������Ϊ"ȷ��"���Ӵ��ھ��
	int CtrlID = ::GetDlgCtrlID(ButtonWnd);//��ÿؼ�ID
	SendMessage(wnd, WM_COMMAND, MAKEWPARAM(CtrlID, BN_CLICKED), LPARAM(ButtonWnd));//���Ϳؼ���Ϣ
	return 0;
}





http://hi.baidu.com/3582077/item/90827a51687894abacc8571b


�ھ�ʮһ��CreateFont����һ�����壬��������������HFONT


HFONT CreateFont(
	int nHeight,//�ַ��߶�
	int nWidth,//�ַ���ȣ�nHeight ��nWidth����ָ�������С
	int nEscapement,//�ı���ʾʱ����б�Ƕȣ����ַ������Ͻ�Ϊԭ�㣬������ʾ˳ʱ����ת��������ʱ�루��2700����ת270�ȣ�
	int nOrientation,//�ַ���ʾʱ����б�Ƕȡ�nEscaperment��nOnentation����������һ��ȡ0�Ϳ����ˡ�
	int fnWeight,//�����������������ϸ���򣬷�Χ��0��1000֮�䡣��FW_NORMAL������
	DWORD fdwItalic,//ָ�������Ƿ���б��true������б���֣�false����
	DWORD fdwUnderline,//ָ�������Ƿ�����»��ߣ�true�У�falseû�С�
	DWORD fdwStrikeOut,//ָ�������Ƿ���ʾɾ���ߣ�ȡֵͬ�ϡ�
	DWORD fdwCharSet,//ָ���ַ�������DEFAULT_CHARSET��Ĭ�ϣ�
	DWORD fdwOutputPrecision, //ָ��������ȣ���OUT_DEFAULT_PRECIS��Ĭ�ϣ�
	DWORD fdwClipPrecision,//ָ���ü����ȣ���CLIP_DEFAULT_PRECIS��Ĭ�ϣ�
	DWORD fdwQuality,//�ַ������������DEFAULT_QUALITY��Ĭ�ϣ�
	DWORD fdwPitchAndFamily,//�ַ���࣬��DEFAULT_PITCH(Ĭ�ϣ�
	LPCTSTR lpszFace//�������ƣ���"����","����".
);


��׼�����������䣺


HFONTFont = CreateFont(20, 20, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
	CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH,
	"����");


����ĺ�������������


�ھ�ʮ����BeginPath����һ��·��


���豸DC������������һ��·�����ٵ��û�ͼ�����ڿ���·����DC�ϵĽ��в�������û��ʵ��ͼ�Σ�������·������Щ·���ǿ�����������ȷʵ���ڡ������Ե�������������·�����в���, ��StroekPath�������õ�ǰ�������·�������ﻹҪ˵��һ�㣬���������еĻ�ͼ����֧��·���ġ��������֧��·���Ļ�ͼ������


AngleArc


Arc��������


ArcTo
Chord
CloseFigure
Ellipse����Բ
ExtTextOut����ı�
LineTo ��ֱ�ߣ���MoveToEx�������ʹ��
MoveToEx ��ֱ��
Pie����ͼ����
PolyBezier
PolyBezierTo
PolyDraw
Polygon
Polyline
PolylineTo
PolyPolygon
PolyPolyline
Rectangle������
RoundRectԲɫ����
TextOut����ı�


������Ҫ����������Щ��������·���󣬾���EndPath��������·��


�ھ�ʮ����StrokePath�õ�ǰ�����·��


����ֻ��һ��������DC�����


���ӣ���һ��������ʾ�ο���


#include<windows.h>
int main()
{
	HWND wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
	HDC dc = GetDC(wnd);
	HFONTFont = CreateFont(50, 50, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH,
		"����");//��������
	HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));//������ɫ����
	SelectObject(dc, pen);//ѡ�뻭��
	SelectObject(dc, Font);//ѡ������
	SetBkMode(dc, TRANSPARENT);//�����ı�������ɫΪ͸��
	while (1)
	{
		BeginPath(dc);//����·��
		TextOut(dc, 0, 0, "ABC", 3);
		EndPath(dc);//����·��
		StrokePath(dc);//�õ�ǰ�������·��
		Sleep(300);
	}
	return 0;
}


�ھ�ʮ�ĸ�SetWindowRgn���ô�����ʾ����


�������� : int
	SetWindowRgn(
		HWND hWnd,//Ҫ���õĴ��ھ��
		HRGN hRgn,//�����������õĴ�����ʾ������������������
		BOOL bRedraw//ָ�������Ƿ��ػ���true�ػ�


	);


SetWindowRgn������������һ�����ڵ���ʾ�������Ա����ṩ���������һ�����򣬶��ú����ĵڶ�������hRgn��ָ�����������


����������ͨ��CreateRectRgn����������һ���������򣩻�ȡ�����Ƶĺ�������CreateEllipticRgn������һ��Բ�����򣩡�


���ӣ���һ������ֻ��ʾ���ķ�֮һ����ʲô����Ϊ���Ͳ���Ҫ˵�˰ɣ�


#include<windows.h>
int main()
{
	HWND wnd = ::FindWindow(NULL, "�ޱ���.txt - ���±�");
	RECT rect;
	GetWindowRect(wnd, &rect);//�������ڣ����ǿͻ�����
	int Width = rect.right - rect.left;
	int Height = rect.bottom - rect.top;
	HRGN hRgn = ::CreateRectRgn(0, 0, Width / 4, Height / 4);//����Ȥ�����ѿ��԰�����CreateRectRgn��������CreateEllipticRgn����
	SetWindowRgn(wnd, hRgn, true);
	return 0;
}


��ô���������ǲ���ֻ��ʾ���ķ�֮һ������ʱ��GetClientRect������ô��ڴ�С�Ƕ����أ����ڵĴ�С����û�䣬��ԭ����һ��
SetWindowRgn����ֻ�����ô�����ʾ���򣬲��������ô��ڴ�С.


��Ҫ��λ�ô�����ʾ���򲿷��أ���GetWindowRgn�������ú�����ȡ������ʾ��������


�ھ�ʮ���CombineRgn�ϲ���������


�������壺int


CombineRgn(


	HRGN hDestRgn, //����������ľ��


	HRGN hSrcRgn1,//Ҫ�ϲ���������1


	HRGN hSrcRgn2//Ҫ�ϲ���������2


	int nCombineMode//ָ��������κϲ�


);


����Ҫע�����hDesRgn, ������һ���Ѵ�����������


������nCombineMode������ȡֵ�Լ���ȡֵ����ȡ�Ĳ���


RGN_AND ����������ص�����


RGN_OR �����������


RGN_DIFF hSrcRgn1δ�ص��Ĳ���


RGN_XOR hSrcRgn1��hSrcRgn2δ�ص��Ĳ���


RGN_COPY ����hSrcRgn1(hSrcRgn1���֣�


	���ӣ���FillRgn���������������Ĺ�ͬ����


#include<windows.h>
	int main()
{
	HWND wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
	HDC dc = GetDC(wnd);
	HRGN hRect = CreateRectRgn(0, 0, 200, 200);
	HRGN hElliptic = CreateEllipticRgn(100, 100, 250, 250);
	HRGN ComRgn = CreateRectRgn(0, 0, 0, 0);
	CombineRgn(ComRgn, hRect, hElliptic, RGN_AND);
	while (1)
	{
		FillRgn(dc, ComRgn, CreateSolidBrush(RGB(255, 0, 0)));//����FillRgn�����������
		Sleep(300);
	}
	return 0;
}


�ھ�ʮ����GetPixel����DC��ȡһ����������ɫֵ


�ú�����һ����������DC������������ָ������㣬�������ظ���������ɫֵ��������Ҫ˵�����ǣ���ò�Ҫֱ�ӻ�ȡDC����ɫֵ����CreateCompatibleDC��������һ�����ݵ�DC��Ȼ������BitBlt������DC������ݸ��Ƶ����ݵ�DC�����GetPixel������ȡ����DC�����ɫֵ�������Ļ����Ͳ����ʲô���⡣


�磺


HWND wnd = FindWindow(NULL, "�ޱ���.txt- ���±�");


HDC dc = GetDC(wnd);


HDC memDC = CreateCompatibleDC(dc);


RECT rect;


GetClientRect(wnd, &rect);


HBITMAP bmp;
bmp = CreateCompatibleBitmap(dc, rect.right, rect.top);
SelectObject(memDC, bmp);
BitBlt(memDC, 0, 0, rect.right, rect.top, dc, 0, 0, SRCCOPY);


COLORREF clr = GetPixel(memDC, 10, 10);//��ȡ�ͻ��������10.10����ɫֵ


���ӣ�������λͼ����


˵����


Ҫ����һ���������λͼ���ڣ����ȱ���û�����������λͼ����������ʲô�����أ���ҿ�һ��StretchBlt�������flower1λͼ��


�������Ǻ�ɫ�����������ǰ�ɫ���������ǿ�����GetPixel�����ж���Щ�����Ǻ�ɫ, ֪������Щ�����Ǻ�ɫ���Ҿ��ǿ�����CreateRectRgn��������һ�����������������������CombineRgn���������������ӵ�һ��������������Ϳ��Ի�ȡ�����ֵ�������


�������£�����StretchBlt�����������λͼΪ����


#include<windows.h>
int main()
{


	HWND wnd = FindWindow(NULL, "�ޱ���.txt- ���±�");
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
			if (GetPixel(memDC, x, y) == 0)//����Ǻ�ɫ
			{


				HRGN pRgn = CreateRectRgn(x, y, x + 1, y + 1);//��������
				CombineRgn(bmRGN, bmRGN, pRgn, RGN_OR);//��pRgn��ӵ�bmRGN������
			}
		}
	SetWindowRgn(wnd, bmRGN, TRUE);
	while (1)
	{
		SelectObject(memDC, hBmp1);
		StretchBlt(dc, 0, 0, bmInfo.bmWidth, bmInfo.bmHeight, memDC,
			0, 0, bmInfo.bmWidth, bmInfo.bmHeight, SRCAND);//��λ������ϲ�DC
		SelectObject(memDC, hBmp2);
		StretchBlt(dc, 0, 0, bmInfo.bmWidth, bmInfo.bmHeight, memDC,
			0, 0, bmInfo.bmWidth, bmInfo.bmHeight, SRCPAINT);//��λ������ϲ�DC
		Sleep(300);
	}
	return 0;
}


����Ч����


��Ӧ�ĺ�������SetPixel���������һ�����ص����ɫֵ


�ھ�ʮ�߸�PathToRegion��һ��DC���·��ת����ѡ����HRGN)


����ֻ��һ����������ת��·����DC������������������


���ӣ�����һ�����ִ���


#include<windows.h>
int main()
{
	HWND wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
	HFONTFont = CreateFont(60, 60, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH,
		"����");//����һ������
	HDC dc = GetDC(wnd);
	BeginPath(dc);//����·��
	SelectObject(dc, Font);
	SetBkMode(dc, TRANSPARENT);
	TextOut(dc, 0, 0, "���ִ���", 8);//�γ�·��
	EndPath(dc);//����·��
	HRGN rgn = ::PathToRegion(dc);//��·��ת����ѡ����rgn���ո�����
	SetWindowRgn(wnd, rgn, TRUE);//���ô�����ʾ����
	return 0;
}


�ھ�ʮ�˸�GetWindowLong��ȡһ�����ڵ���Ϣ


�������壺LONG GetWindowLong(HWND hWnd��intnlndex);


�ڶ�������nIndexָ����ȡ����ʲô��Ϣ��������������ȡֵ�������԰ٶȰٿƣ�


GWL_EXSTYLE�������չ���ڷ�� ��Ӧ��CreateWindowEx������DWORD wExStyle����


GWL_STYLE����ô��ڷ�� ��Ӧ��CreateWindowEx������DWORD dwStyle����


GWL_WNDPROC����ô��ڹ��̵ĵ�ַ����Ӧ��WNDCLASS�ṹ�� pfnWndProc��Ա


GWL_HINSTANCE WNDCLASS�ṹ��hInstance��Ա


GWL_HWNDPAAENT����������ڴ��ڣ���ø����ھ����


GWL_ID : ��ô��ڱ�ʶ������ID��


	�����ķ���ֵָ��������Ϣ������nIndexȡֵ����


	�ھ�ʮ�˸�SetWindowLong����һ��������Ϣ


	�������壺LONG SetWindowLong��HWND hWnd��int nlndex��LONG dwNewLong);


nIndex�����Ľ��͸�GetWindowLong������nIndex����һ����dwNewLong����ָ��Ҫ���õ���Ϣ����GetWindowLong�����ķ���ֵ���Ӧ��


���ӣ�ȥ��һ�����ڵı�����


#include<windows.h>
int main()
{
	HWND wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
	LONG dw = GetWindowLong(wnd, GWL_STYLE);//��ȡ���ڷ��
	dw ^= WS_CAPTION;//ȥ��dw��WS_CAPTION(����)����
	SetWindowLong(wnd, GWL_STYLE, dw); //���ô��ڷ��
	ShowWindow(wnd, SW_MINIMIZE);//��С������
	return 0;
}


�ھ�ʮ�Ÿ�CreateFileMapping����һ���ڴ��ļ�ӳ������ڴ棨���������ļ�ӳ���������


��һ���ļ�ӳ�䵽�ڴ棬��ӳ�������ڴ�Ķ�д���͸������е��ļ���д��һ���ģ������ļ��ڴ�ӳ�䴦����̵��ļ�ʱ��ʡȥ���ļ�I / O����������ر��ʺϴ���ϴ���ļ���


�������壺HANDLE
CreateFileMapping(
	HANDLE hFile,//Ҫӳ����ļ������ͨ��CreateFile������ã����ΪINVALID_HANDLE_VALUE��������������ǹ����ڴ�


	LPSECURITY_ATTRIBUTES lpFileMappingAttributes,//��ָ�����صľ���Ƿ���Ա��ӽ������̳�,һ��ΪNULL
	DWORD flProtect,//ָ��ӳ��򿪷�ʽ��PAGE_READONLY��ֻ������PAGE_READWRITE����д��
	DWORD dwMaximumSizeHigh,//�ļ�ӳ�����󳤶ȵĸ�32λ
	DWORD dwMaximumSizeLow,//�ļ�ӳ�����󳤶ȵĵ�32λ,
	LPCWSTR lpName//�ļ��ڴ�ӳ���������ƣ�����ΪNULL
);


�����ļ�������󳤶ȿ��ܻᳬ��32λ��С�������������������32λ������dwMaximumSizeHigh��dwMaximumSizeLow)����ʾһ���ļ�����󳤶ȣ���������������ȡֵ��Ϊ0ʱ��Ҳ�����ļ���󳤶�Ϊ0ʱ�����ô����ļ���ʵ�ʳ��ȡ�


��һ�ٸ�MapViewOfFile��һ���ļ�ӳ�����ӳ�䵽��ǰӦ�ó���ĵ�ַ�ռ�


�������壺LPVOID
MapViewOfFile(
	HANDLE hFileMappingObject,//�ļ�ӳ�����ľ����CreateFileMapping�������
	DWORD dwDesiredAccess,//ӳ�䷽ʽ��FILE_MAP_WRITE (��д��FILE_MAP_READ��ֻ����
	DWORD dwFileOffsetHigh,//�ļ���ӳ�����ĸ�32λ��ַ 
	DWORD dwFileOffsetLow,//�ļ���ӳ�����ĵ�32λ��ַ ���ߵͿ�Ϊ0
	DWORD dwNumberOfBytesToMap//�ļ���Ҫӳ����ֽ�����Ϊ0ӳ�������ļ�ӳ����� 
);


���������ļ�ӳ�����ڴ��е���ʼ��ַ��


���ӣ���дһ���ļ�������E������һ����Ϊa.txt���ļ�������Ϊ0123456789��


#include<windows.h>
#include<stdio.h>
int main()
{
	HANDLE hFile = CreateFile("e:\\a.txt", GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);//�Զ�д��ʽ���ļ�
	HANDLE hMap = ::CreateFileMapping(hFile, NULL, PAGE_READWRITE, NULL, NULL, NULL);
	LPVOID lpBase = ::MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, 0);
	for (int i = 0; i < 10; i++)//��ӳ���ڴ��е�����
		printf("%c ", ((char *)lpBase)[i]);
	printf("\n");
	for (i = 0; i < 10; i++)//д�����ݵ�ӳ���ڴ���
		((char *)lpBase)[i] = L'A' + i;
	return 0;
}


��ʱ��ȥ��E����a.txt�ļ����ǲ������������ȫ��Ϊ"A"�ˡ�


����Ҫ˵�����ǣ��ļ��򿪷�ʽ��ӳ��򿪷�ʽ��ӳ�䷽ʽ������һ�µģ�������ֻ�����ļ�������ֻдӳ����ļ�





http://hi.baidu.com/3582077/item/33998ace7814e326a0b50a19


��һ����һ��OpenFileMapping��ȡCreateFileMapping�����������ļ�ӳ�������


�������壺HANDLE
OpenFileMappingW(
	DWORD dwDesiredAccess,//ȡֵ�ο�MapViewOfFile������dwDesiredAccess����
	BOOL bInheritHandle,//����CreateFileMapping������lpFileMappingAttributes�������������ܱ��½��̼̳У�ΪFALSE
	LPCWSTR lpName//ָ����ȡ�ĸ��ļ�ӳ�����������Ӧ��CreateFileMapping������lpName����
);


���������ļ�ӳ���������


���ӣ������̼䴫������


����1������룺


#include<windows.h>
#include<stdio.h>
int main()
{
	char Data[11] = "0123456789";
	HANDLEhMap = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 11, "ShareMemory");
	LPVOID lpBase = ::MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, 0);
	strcpy((char *)lpBase, Data);//д������
	while (1)
	{
		Sleep(2000);
	}
	return 0;
}
����2������룺


#include<stdio.h>
#include<windows.h>
int main()
{
	HANDLE hMap = ::OpenFileMapping(FILE_MAP_WRITE, FALSE, "ShareMemory");
	LPVOID lpBase = ::MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, 0);
	printf("ShareMemory Data:%s\n", lpBase);//�������
	return 0;
}


��һ�������CopyMemory����һ���ڴ�


�������壺��VOID CopyMemory(
	PVOID Destination, //Ŀ�ĵ�ַ
	CONST VOID *Source, //Դ��ַ
	DWORD Length //���ƶ����ֽ�
);
���������C���Ե�memcpy����һ����������ٸ����ӣ�
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


��һ��������SetParent���ã����ģ�һ���Ӵ��ڵĸ�����


�ú�����������������һ�����Ӵ��ڵľ�����ڶ����Ǹ����ڵľ����


��������ھ��Ϊ�գ��������洰����Ϊ������


���ӣ��Ѽ��±���״̬���ĸ����ڸ�Ϊ�༭�򴰿�


��spy++�鿴���±��༭�򴰿ڵ�����Ϊ"Edit", ״̬��Ϊ"msctls_statusbar32"(���ܻ��в��죬���������Spy++�鿴��


#include<windows.h>
	int main()
{
	HWND wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
	HWND EditWnd = FindWindowEx(wnd, NULL, "Edit", NULL);//���һ�ȡ�༭�򴰿ھ��
	HWND StatusWnd = FindWindowEx(wnd, NULL, "msctls_statusbar32", NULL);//���һ�ȡ״̬�����ھ��
	::SetParent(StatusWnd, EditWnd);//����״̬��������
	RECT rect;
	GetClientRect(StatusWnd, &rect);//��ȡ״̬���ͻ�����С


	//�ƶ�״̬�����ڣ�����༭�򴰿ڲ���״̬���ĸ����ڣ���״̬�����Ʋ����༭�򴰿ڵ�
	MoveWindow(StatusWnd, 0, 0, rect.right, rect.bottom, TRUE);


	return 0;
}


��һ�����ĸ�OpenClipboard��һ�����а�


���а���ʲô��˼�أ����԰�������һ���ڴ棬����ڴ���Ա��κν��̵�����غ������ж�д����ʵ�ϣ�������ƽ���ĸ���ճ�������ڶ�д����ڴ棬������ѡ��һ�����֣�Ȼ���һ���ѡ���ƣ���ʱ��Ӧ����ͻ����OpenClipboard�����򿪼��а壬������д�����ݣ�


��������Ҫ�������а��ʱ��͵���CloseClipboard�����رռ��а壬���а岻��ͬʱ���������򿪣�Ҳ����˵������������Ѿ�����OpenClipboard�򿪼��а��ˣ�����û�е���CloseClipboard�رռ��а�Ļ�����ô�����������OpenClipboard�ͻ�ʧ�ܣ���һ�����������ӿ���˵����


�������ֻ��һ����������һ�����ھ����Ҳ���Ǿ������ĸ���������и���ճ������������Ҳ�㣩�����ΪNULL�����������������Ľ����������


���ӣ���ճ������ʧЧ


#include<windows.h>
int main()
{
	OpenClipboard(NULL);
	while (1)
		Sleep(1000);
}


�������������˼��а�ȴ�����ر��������������������޷�����OpenClipboard�����򿪼��а壬�޷��򿪼��а壬��ȻҲ���޷�����ճ��������


��һ�������SetClipboardDataд��һ�����ݵ����а壨���ü��а�����ݣ�


HANDLE SetClipboardData(UINT uFormat, HANDLE hMem);


������ʹ��windows�ĸ���ճ����ʱ�򣬲����ܸ������֣�Ҳ�ܸ����ļ���ͼƬ�ȡ�����uFormatָ��Ҫд�����ʲô���ݡ�


uFormat�ĳ���ȡֵ���£�


CF_UNICODETEXT����Unicode���ֵ��ڴ��


CF_BITMAP���豸��ص�λͼ��ʽ��λͼ��ͨ��λͼ������͸����а��


CF_TEXT��NULL��β��ANSI�ַ����ַ���


�ڶ���ָ��洢Ҫд��������ڴ棬ע�⣬�洢���ݵ��ڴ�������ڶ��з���ġ�


����1��д��ASCII�ַ��������а�


#include<windows.h>
#include<string.h>
int main()
{
	char *pData = new char[15];//�ڶ��������ڴ�
	strcpy(pData, "ABCDEFG");
	OpenClipboard(NULL);//�򿪼��а�
	EmptyClipboard();//��ռ��а������
	SetClipboardData(CF_TEXT, pData);//�����а���д������
	CloseClipboard();//�رռ��а�
	delete pData;
	return 0;
}


//��㵽�����������ֵĵط����һ�->ճ����д���Ƿ�ɹ�


����2��д����ַ�����Unicode�������а�


#include<string.h>
#include<windows.h>
int main()
{
	WCHAR *pData = new WCHAR[15];
	WCHAR str[15] = L"ABC����D";//��L��ASCIIת����Unicode
	CopyMemory((void *)pData, (void *)str, sizeof(str));//�൱��ASCII�ַ���������strcpy
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, pData);
	CloseClipboard();
	return 0;
}


��һ��������GlobalAlloc�Ӷ��з���һ����Ŀ���ֽ���


HGLOBAL
WINAPI
GlobalAlloc(
	UINT uFlags,//��������(��ʽ)
	DWORD dwBytes//��������ֽ�
);


uFlags����ȡֵ��
GMEM_FIXED ����̶����ڴ�, ����ֵ��һ��ָ��


GMEM_MOVEABLE ����ֵ��һ���ڴ���������GlobalLock��������һ���ڴ����������ڴ�����Ӧ���׵�ַ���������ڴ���ָ�����ڴ�飬��Ӧ�ĺ����ǣ�GlobalUnlock


��Ӧ���ͷ��ڴ溯����GlobalFree�����ﻹ��˵��һ������GlobalSize����������ڴ�����ö�Ӧ�ڴ���С


���ӣ�GlobalAlloc����Ӧ��


#include<stdio.h>
#include<windows.h>
int main()
{
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, 8);//��GEME_MOVEABLE��ʽ�����ڴ�


	DWORD dwSize = GlobalSize(hMem);//��ȡ�ڴ���С
	int *pNumber = (int *)GlobalLock(hMem);//���ڴ���ת�����ڴ��׵�ַ
	pNumber[0] = 5; pNumber[1] = 6;
	printf("�ڴ���С%d\n%d,%d\n", dwSize, pNumber[0], pNumber[1]);
	GlobalFree(hMem);//�ͷ��ڴ�
	return 0;
}


��һ�����߸�GetClipboardData�ú�����ü��а�������ݣ��������ؼ��а��ڴ���


�ú���ֻ��һ��������ָ����ȡ����ʲô���͵����ݣ���SetClipboardData������uFormat�������Ӧ��������һ�����⣬���֪�����а�洢����ʲô���������أ���IsClipboardFormatAvailable�������������ֻ��һ���������磺IsClipboardFormatAvailable(CF_TEXT)


�����������жϵ�ǰ���а���û�к���CF_TEXT���ݣ�����еĻ��������棨TRUE�����񷵻ؼ١���������������ȴ򿪼��а壬Ҳ�����������á�


ע�����������а��������CF_UNICODETEXT��ʽ�ģ���CF_TEXT���ʹ�Ҳ�ǿ��Եģ���Ϊwindowsϵͳ���Զ�����ת����


���ӣ���ȡ���а����CF_TEXT���ݣ�����㸴��һ�����֣�


#include<stdio.h>
#include<windows.h>
int main()
{
	if (IsClipboardFormatAvailable(CF_TEXT))//�жϼ��а����Ƿ���CF_TEXT����
	{
		::OpenClipboard(NULL);
		HGLOBAL hGlobal = GetClipboardData(CF_TEXT);//��CF_TEXT��ʽ�򿪼��а�
		char *pGlobal = (char *)GlobalLock(hGlobal);//��ü��а��ڴ���׵�ַ��ֱ��ת��Ҳ���ԣ���(char *)hGlobal
		printf("%s\n", pGlobal);//������а��������


		GlobalUnlock(hGlobal);
		CloseClipboard();
	}
	return 0;
}


��һ����˸�Shell_NotifyIcon����������ע��ͼ�꣨���������̲˵���


(PS�����쿴��һ����ǰд������������������������Ϊ���̲˵��������������ƺ�ѹ���͸��˵�û��ϵ�����룬Ӧ������ʱ������MFC�￴������������Ǹ���������һ�����̲˵����Ҿ��������̲˵��ˣ�ȴû��ʵ�����̲˵��Ĺ��ܣ�����������Ӱ�������������÷����Լ�������˼����Ҳ�Ϸ���


	�������壺Shell_NotifyIcon(DWORD dwMessage, PNOTIFYICONDATAWlpData);


Ҫ��ע��һ�����̲˵�����������ṩһЩ��Ϣ������������Ҫ��ʾ��ͼ�꣬ϵ���̲˵������ĸ����ڣ��ϸ���˵�������̲˵���������Ϣ�����͸��ĸ����ڣ�


����Щ��Ϣ����Shell_NotifyIcon�����ĵڶ�������lpDataָ��������һ��NOTIFYICONDATAW�ṹָ�롣


NOTIFYICONDATAW�ṹ���弰����Ա��˼���£�


typedef struct _NOTIFYICONDATAW {
	DWORD cbSize;//ָ��NOTIFYICONDATA�ṹ��С����sizeof(NOTIFYICONDATA)������ֵ��
	HWND hWnd;//���ھ���������������ͼ���������Ϣ�����͸��������
	UINT uID;//��ʶ���̲˵���ΨһID�š�
	UINT uFlags;//ָ���ṹ����Щ��Ա��Ч��������NIF_ICON����ӦhIcon), NIF_MESSAGE����ӦuCallbackMessage),


	//NIF_TIP(��Ӧ szTip)��������|��λ������������һ��
	UINT uCallbackMessage;//�Զ�����Ϣ��������в�ͼ���ϲ�������Ϊ�����������Ϣ��hWnd��Ա��Ӧ�Ĵ���
	HICON hIcon;//ͼ������
	WCHAR szTip[64];//���ͣ��������ͼ���ϲ�������ʾ��Ϣ����
} NOTIFYICONDATA, *PNOTIFYICONDATA;


dwMessage����ָ��Ҫ���еĲ���������ȡֵ��NIM_ADD��������̲˵�����NIM_DELETE��ɾ��һ�����̲˵�����NIM_MODIFY ���޸�һ�����̲˵���


�˽�������Щ�������򵥵�������������ʾһ�����̲˵���ͼ�꣬����ʲôҲ������


����e������һ����Ϊ"i.ico"��ͼ��


�������£�


#include<windows.h>
int main()
{
	NOTIFYICONDATA notify;//����һ�����̲˵���Ϣ�ṹ
	notify.cbSize = sizeof(NOTIFYICONDATA);//���ýṹ��С
	notify.hIcon = (HICON)LoadImage(NULL, "e:\\i.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE);//����ͼ����
	notify.uFlags = NIF_ICON;//ָ����Щ��Ա��Ч
	::Shell_NotifyIcon(NIM_ADD, &notify);//������̲˵�
	while (1)
	{
		Sleep(1000);//��������˳����Զ�ж�����̲˵�
	}
	return 0;
}


��ô���������ǲ�����һ��ͼ����ʾ�ˣ�����ʱ�����󵥻�����˫�������ϵ�ͼ�궼û��Ӧ��


�������Ӧ��������Ϣ�Ļ�����ʹ NOTIFYICONDATA�ṹ��uCallbackMessage��Ա��Ч����������������̲˵�ͼ���ϵ�����˫���󣬾ͻ����uCallbackMessage��Ա��Ӧ����Ϣ�����һ�����ָ�����ھ������Ȼ�����������Ϣ�����͸��ĸ������ء�


����2�����������̲˵�Ӧ��


����Ӧ�ã���������Լ��Ĵ��ڣ��½�һ�� ��Win32 Application"���̡��������API�����������ڲ��˽�Ļ������Բο����ú���CreateWindow.


#include<windows.h>
#include<string.h>
//��WM_USER�Ļ����϶���һ����Ϣ���ͣ����������봰��֮�����Ϣ����
#define WM_TRAYMESSAGE WM_USER+25 
LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);//��������
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASS wndcls; //����һ���洢������ϢWNDCLASS����
	wndcls.cbClsExtra = 0; //Ĭ��Ϊ0
	wndcls.cbWndExtra = 0; //Ĭ��Ϊ0
	wndcls.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); //������ˢ
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW); //���
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR); //����ͼ��
	wndcls.hInstance = hInstance; //Ӧ�ó���ʵ�������WinMain����������
	wndcls.lpfnWndProc = WinSunProc; //������Ϣ������
	wndcls.lpszClassName = "windowclass"; //��������
	wndcls.lpszMenuName = NULL; //���ڲ˵�����û�в˵���ΪNULL
	wndcls.style = CS_HREDRAW | CS_VREDRAW;//�������ͣ�CS_HREDRAW��CS_VERDRAW ����
	//������ˮƽ����ֱ����Ŀ�ȱ仯ʱ�ػ���������
	RegisterClass(&wndcls); //�Ѵ�����Ϣ�ύ��ϵͳ��ע�ᴰ����
	HWND hwnd; //���Դ洢CreateWindow�����������Ĵ��ھ��
	hwnd = CreateWindow("windowclass", "���̲˵�Ӧ��",
		WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);//��������
	NOTIFYICONDATAnotify;//����һ�����̲˵���Ϣ�ṹ
	notify.cbSize = sizeof(NOTIFYICONDATA);//���ýṹ��С
	notify.hIcon = (HICON)LoadImage(NULL, "e:\\i.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE);//����ͼ����
	notify.hWnd = hwnd;//������Ϣ�Ĵ��ھ��
	strncpy(notify.szTip, "���̲˵�", sizeof("���̲˵�"));
	notify.uCallbackMessage = WM_TRAYMESSAGE;//���̲˵������������Ϣ������
	notify.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;//ָ����Щ��Ա��Ч
	::Shell_NotifyIcon(NIM_ADD, &notify);//������̲˵�
	ShowWindow(hwnd, SW_SHOWNORMAL);//���ڴ������ˣ���ʾ��
	UpdateWindow(hwnd); //���´��ڣ��ô��ں����ӳٵ���ʾ
	MSG msg;//��Ϣ�ṹ����
	while (GetMessage(&msg, NULL, 0, 0))//��ȡ��Ϣ
	{
		TranslateMessage(&msg); //�˺������ڰѼ�����Ϣ(WM_KEYDOWN,WM_KEYUP)ת�����ַ���ϢWM_CHAR
		DispatchMessage(&msg); //����������ô��ڹ��̴�����������MSG�����Ϣ����󴫸����̺������ĸ�����
	}
	::Shell_NotifyIcon(NIM_DELETE, &notify);//ж�����̲˵�
	return 0;
}
LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_SYSCOMMAND:
		if (wParam == SC_MINIMIZE)//��С���˴���
		{
			ShowWindow(hwnd, SW_HIDE);//���ش���
		}
		else
		{
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
		break;
	case WM_TRAYMESSAGE:
		if (lParam == WM_LBUTTONDBLCLK)//˫�����̲˵�ͼ��,�����Ϣ��lParam������
		{
			ShowWindow(hwnd, SW_RESTORE);//��ʾ����
		}
		break;
	case WM_CLOSE://�û��ر��˴���
		DestroyWindow(hwnd);//���ٴ��ڣ�������WM_DESTROY��Ϣ
		break;
	case WM_DESTROY://������ڱ�����
		PostQuitMessage(0);//�ý����˳�
		break;
		//δ�������Ϣͨ��DefWindowProc��������ϵͳ����
	default:return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}


	return 0;
}


��һ����Ÿ�FindResource��Ӧ�ó���ģ�����ҳ�һ����Դ


��Դ����MFC�����Դ����λͼ��ͼ�꣬�Ի������Щ��Դ��������exe�ļ���������PE�ļ��ṹ������Ӧ�õĻ���Ӧ�û�������⡣


����������Ƕ�λһ����Դ��ģ�����λ�á�


�������壺HRSRC FindResource(HMODULE hModule,//Ӧ�ó���ģ������NULL��ʾ��ģ����


	LPCTSTR lpName,//��Դ��


	LPCTSTR lpType//��Դ����


);


���е�һ������hModuleӦ�ó���ģ����, ����ģ����NULL���У�������ȡ�����������е�Ӧ�ó���ģ�飬����GetModuleHandle������


��Դ��������Դ��ID��һ��������һ��MFC��һ����ԴID����147����ô�˲���Ӧ����������"#147"������MAKEINTRESOURCE��ת��


�磺MAKEINTRESOURCE(147)


lpType���ڱ�����Դ���ͣ����ǶԻ��򣿲˵���λͼ�������Զ�����Դ������


����ȡֵ���£�


#define RT_CURSOR MAKEINTRESOURCE(1) //���
#define RT_BITMAP MAKEINTRESOURCE(2) //λͼ
#define RT_ICON MAKEINTRESOURCE(3)//ͼ��
#define RT_MENU MAKEINTRESOURCE(4)//�˵�
#define RT_DIALOG MAKEINTRESOURCE(5)//�Ի���
#define RT_STRING MAKEINTRESOURCE(6)//�ַ���
#define RT_FONTDIR MAKEINTRESOURCE(7)
#define RT_FONT MAKEINTRESOURCE(8)//����
#define RT_ACCELERATOR MAKEINTRESOURCE(9)
#define RT_RCDATA MAKEINTRESOURCE(10)
#define RT_MESSAGETABLE MAKEINTRESOURCE(11)


#define DIFFERENCE 11
#define RT_GROUP_CURSOR MAKEINTRESOURCE((DWORD)RT_CURSOR + DIFFERENCE)//�����
#define RT_GROUP_ICON MAKEINTRESOURCE((DWORD)RT_ICON + DIFFERENCE)//ͼ����
#define RT_VERSION MAKEINTRESOURCE(16)
#define RT_DLGINCLUDE MAKEINTRESOURCE(17)


��һ��һʮ��LoadResource������Դָ������HRSRC������Դװ�ص��ڴ档


����������Դ�����ڴ�����HGLOBAL����������LockResource�����ڴ�������ȡ�ڴ��׵�ַ


�������壺


HGLOBAL LoadResource(HMODULE hModule, HRSRC hResiInfo);


hModule����ͬFindResource��Ӧ�Ĳ�һ����ģ������hResiInfo������ӦFindResource�������ص�ֵ


LockResource�������壺LPVOIDLockResource(HGLOBAL hResDate);
hResDate������ӦLoadResource�������ص�ֵ





http://hi.baidu.com/3582077/item/eed4cc5fa6fff43795eb0508


��һ��һʮһ��SizeofResource��ȡһ����Դ�Ĵ�С


�������壺DWORD SizeofResource(


	HMODULE hModule,//ģ������ͬFindResource,LoadResource��ģ����һ��


	HRSRC hResInfo//��Դλ�þ��,��FindResource�������صľ��


);


���ӣ��Զ�����Դ��EXE�ļ�����DLL��˫����EXE�ļ��ͷ������DLL�ļ�����ǰĿ¼


���������½�һ���ؼ�̨���̣���Ҳ�����½�һ��WIN32���̣��������ｨ�Ĳ���MFC���̣����Ի����������������Դ�ļ����������ļ�->�½����ڵ����ĶԻ�����ѡ���ļ���ѡ���ǩ��Ȼ��ѡ�С���Դ�ű���������Ҫ���ľ�������ļ���ȡ����ȷ������ɡ�


�������ǽ�����Դ��ͼ��ResourceView), �һ���Դ�ļ���ѡ������(�ǵð��ļ�����ѡ���У���ѡ��һ��DLL�ļ��������롣��ʱ��ᵯ��һ���Ի�����ʾ����Զ�����Դ����ȡ����������ס�����������Ӧ��FindResource�����ĵ���������lpType��ȡ��ΪDLL��ȷ������������ֻҪ�鿴һ������Զ�����Դ��ID�ţ��Ϳ���ȥ�ô����ˡ��������һ���Դ�ļ���ѡ��"��Դ����", �����Ҳ鿴�Ķ�ӦID����101�����˽������༭�����������´��룺


#include<windows.h>
	int main()
{
	HRSRC hRsrc = FindResource(NULL, MAKEINTRESOURCE(101), "DLL");//������Դλ��
	DWORD dllSize = SizeofResource(NULL, hRsrc);//��ȡ��Դ��С
	HGLOBAL hGlobal = LoadResource(NULL, hRsrc);//������Դ���ڴ�
	LPVOID pBuffer = LockResource(hGlobal);//��ȡ�ڴ��׵�ַ
	char pathName[100];
	GetModuleFileName(NULL, pathName, 100);//���Ӧ�ó�������·����
	int i = 0;
	while (pathName[i] != '\0') i++;//����·�����ַ�������λ��
	//��exe�ĳ�dll��Ȼ�󴴽��ļ�
	pathName[i - 1] = 'l';
	pathName[i - 2] = 'l';
	pathName[i - 3] = 'd';
	HANDLE hFile = CreateFile(pathName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);//�����ļ�
	DWORD dwSize;
	WriteFile(hFile, pBuffer, dllSize, &dwSize, NULL);//д������
	return 0;
}


���У�Ȼ������ɵ�EXE������㸴�Ƶ�һ��Ŀ¼�£�˫������һ�¡���������ͬһĿ¼���ͷų���һ��DLL�ļ���


�����Ӧ�õ��κ��ļ��ϣ��������һ��EXE�ļ����������EXE�ļ�����ִ�����EXE�ļ��󣬻��ͷų�����EXE�ļ���Ȼ��ɾ������


��һ��һʮ����SetLayeredWindowAttributes���ô���͸����


�������壺BOOL SetLayeredWindowAttributes(
	HWND hwnd,//Ҫ���õĴ��ھ��
	COLORREF crKey,//�������һ��������ɫֵ����crKey����ô������ؽ���͸����
	BYTE bAlpha,//ȡֵ��Χ0��255��0��ʾȫ͸����255��ʾ��͸��
	DWORD dwFlags//ָ��crKey����bAlphaֵ��Ч��LWA_COLORKEY��0x1)ָ��crKeyֵ��Ч��bAlphaֵ��Ч��


	//LWA_ALPHA��0x2)�� ʾ bAlpahֵ��Ч��crKeyֵ��Ч��LWA_COLORKEY|LWA_ALPHA��ʾ���߶���Ч
);


��Ҫ����SetLayeredWindowAttributes���ô���͸���ȣ������ô��ھ���WS_EX_LAYERED��0x80000)��չ��ʽ������SetWindowLong�������ã��ú����÷��ο�API ���ú����ھ�ʮ�˸�����SetLayeredWindowAttributes�����ڶ�̬���ӿ�user32.dll���棬���ڵ��ö�̬���ӿ���ĺ�����ο�http://hi.baidu.com/3582077/blog/item/8471dcdd82e15e205882dd68.html���������õڶ��ַ�����LoadLibrary������������÷������Ŀ��Բο� API���ú�������ʮ�Ÿ���


����Ĵ����������ޱ�����±�Ϊ��


#include<windows.h>
int main()
{
	HWND wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
	SetWindowLong(wnd, GWL_EXSTYLE, GetWindowLong(wnd, GWL_EXSTYLE) | 0x80000);
	typedef BOOL(WINAPI *FSetLayeredWindowAttributes)(HWND, COLORREF, BYTE, DWORD);
	FSetLayeredWindowAttributes SetLayeredWindowAttributes;
	HINSTANCE hInst = LoadLibrary("User32.DLL");
	SetLayeredWindowAttributes = (FSetLayeredWindowAttributes)GetProcAddress(hInst, "SetLayeredWindowAttributes");
	int value = 0;
	while (1)
	{
		if (value == 256) value = 0;
		SetLayeredWindowAttributes(wnd, RGB(0, 0, 0), value, 0x2);//0x2 �õڶ���������Ч��
		value++;
		Sleep(50);
	}
	return 0;
}
��һ��һʮ����SetROP2����DC��ͼģʽ


ͨ������£����������SetROP2�������û�ͼģʽ����ôĬ�ϵ�DC��ͼģʽ����R2_COPYPEN��ֱ����Դֵ���ǣ�����Rectangle������������ѡ��һ����ɫ��ˢ���磺


HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));


SelectObject(hdc, brush); ��ô����Rectangle��һ�������ﻭһ��0��0��100��100�ľ��ξ���


Rectangle(hdc, 0, 0, 100, 100);


���û����Rectangle֮ǰ�������ⲿ������ȫ����ɫ��


����ͼ��




(Ϊ�˷��㣬�������Ϊdest)


��ô����Rectangle֮���ⲿ������Ӧ���������ģ�




������ͳ�Ϊsrc��


����������ÿһ�����ض���һ��RGB��ɫֵ����0, 255, 0��255, 0, 0����Rectangle��Ҫ���ľ��Ǻϲ�������������(dest��src)�����ڲ���R2_COPYPEN��ͼģʽ��ֱ����src���ǵ�dest����ô�����ڴ�������ʾ�Ľ��Ӧ��ȫ�Ǻ�ɫ��Ҳ����ÿ������ֵ���Ǻ�ɫ��


����R2_MASKPENģʽ������ǲ��ð�λ�루AND���ϲ�����ͼƬ������ͼƬ�Ķ�Ӧ������ɫֵ���а�λ�����㡣


Ҳ����RGB(0, 255, 0)&RGB(255, 0, 0)�Ľ�����Ǵ���������ʾ��������ɫ��


��ô�����SetROP2���û�ͼģʽΪR2_MASKPEN���ٵ���Rectangle��������ʾ��Ӧ����������


������λ��ϲ���Ľ����RGB(0, 255, 0)&RGB(255, 0, 0)�Ľ����0��Ҳ������ɫֵRGB(0, 0, 0)��ɫ��


���Ƶģ����а�λ�򣬰�λ���ȡ�������㣬�ָ�������ģʽ��������ͣ�����Programming Windowswith MFC��


R2_NOPdest = destR2_NOTdest = NOT destR2_BLACK dest = BLACKR2_WHITEdest = WHITER2_COPYPEN dest = srcR2_NOTCOPYPEN dest = NOTsrcR2_MERGEPENNOT dest = (NOT dest) OR srcR2_MASKPENNOT dest = (NOT dest) ANDsrcR2_MERGENOTPENdest = (NOT src) OR destR2_MASKNOTPEN dest = (NOT src) ANDdestR2_MERGEPEN dest = dest OR srcR2_NOTMERGEPEN dest = NOT(dest ORsrc)R2_MASKPEN dest = dest AND srcR2_NOTMASKPENdest = NOT(dest ANDsrc)R2_XORPENdest = src XOR destR2_NOTXORPENdest = NOT(src XOR dest)


���ӣ���R2_MASKPEN ��ͼģʽ�ڴ����ﻭһ������


#include<windows.h>
int main()
{


	HWND wnd = FindWindow(NULL, "�ޱ���.txt- ���±�");
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


����Ч����




�����⼸��ģʽ��һ�£���������ֻ���ʲô��ͬ��


��һ��һʮ�ĸ�SetMapMode����DCӳ��ģʽ
Ĭ�ϵ�ģʽ��MM_TEXT, һ����λ����һ������, Ҳ���ǵ������Rectangle�Ⱥ�����ͼʱ, �����ĵ�λ������, ��Rectangle(hdc, 0, 0, 100, 100); ��ʱ��0, 0�Ǵ��ڵ����Ͻ�, һ����300, ��300���صľ���.
�������ģʽ��һ�µĻ�, ����Ͳ���������, ��MM_LOMETRICģʽ�ĵ�λ����0.1����, ��ôRectangle(hdc, 0, 0, 100, 100)�����ľ���Ӧ����100*0.1mm��, 100 * 0.1mm��, Ҳ����1���׿��, ��������NM_LOMETRICģʽ, �ٵ���Rectangle(hdc, 0, 0, 100, 100)��, �������ڴ�������ʾһ������, ����Ϊʲô��, ��������Ӧ�����겻ͬ.
NM_TEXTģʽ�´������ϽǶ�Ӧ�����0, 0, �������¶��ǵ���, ����ͼ:


�������Զ���ģʽ, ��NM_TEXTģʽ, ���ڵ����궼�������� :


	��ô����������괦������ģʽ��, ���ڴ����ﻭ����, Y�������Ϊ�Ǹ���, ���������Rectangle����Ӧ��������Rectangle(0, 0, 100, -100); ������ĵ�λ��0.1mm


	�����������ģʽ������


	MM_TEXT 1 pixel


	MM_LOMETRIC 0.1 mm


	MM_HIMETRIC 0.01 mm


	MM_LOENGLISH 0.01 in.


	MM_HIENGLISH 0.001 in.


	MM_TWIPS 1 / 1440 in.(0.0007 in.)


	MM_ISOTROPIC User - defined(x and y scale identically)User - defined


	MM_ANISOTROPIC User - defined(x and y scale independently)User - defined


	in.��Ӣ�����д.


	������һ�����ڻ�һ��5���׳���ֱ�ߣ�ӳ��ģʽΪMM_LOMETRIC


#include<windows.h>
	int main()
{


	HWND wnd = FindWindow(NULL, "�ޱ���.txt- ���±�");
	HDC dc = GetDC(wnd);
	::SetMapMode(dc, MM_LOMETRIC);//����ӳ��ģʽ
	while (1)
	{
		MoveToEx(dc, 0, -50, NULL);
		LineTo(dc, 500, -50);//500�������أ���λ��0.1mm
		Sleep(200);
	}
	return 0;
}
//�ó���ȥ��һ���Ǹ��ߣ����ǲ��������ף�û���ӣ�û��ϵ����PS��һ��
//�����׵Ŀ��ͼ�񣬶Ա�һ�¡�


��һ��һʮ���DPtoLP���豸����ת�����߼�����


��ʵ���ǽ�MM_TEXTģʽ��������Ϊ��λ�������ת���ɵ�ǰģʽ�µ����꣬������MM_TEXTģʽ��150��150��������λ����MM_LOMETRICģʽ���������Ҳ����˵50*0.1mm�Ƕ������ء�


����������������ӣ���150��150�����MM_TEXTģʽ�µ������ת����MM_LOMETRICģʽ�¶�Ӧ�������.


#include<windows.h>
#include<iostream.h>
int main()
{


	HWND wnd = FindWindow(NULL, "�ޱ���.txt- ���±�");
	HDC dc = GetDC(wnd);
	POINT pt;
	pt.x = pt.y = 150;


	//���õ�ǰģʽ����Ե�ǰģʽ��ת������������ã�Ĭ����MM_TEXT��MM_TEXTתMM_TEXT�������һ��
	SetMapMode(dc, MM_LOMETRIC);


	DPtoLP(dc, &pt, 1);//dc���豸�����ģ��ڶ���������һ��POINTָ�룬������ָ���������������ڶ��ת��


	//�磺POINTpt[2]={{100,100},{200,200}};DPtoLP(dc,pt,2);
	cout << pt.x << "," << pt.y << endl;
	return 0;
}
��������������� 469�� - 469


�������ݵ������ö���, Ҳ����˵��MM_LOMETRICģʽ��469�� - 469���������MM_TEXTģʽ��100��100���������λ������ͬ�ġ�


���ӣ���һ�������������ģʽ�»�ͬһ���ȵ���


#include<windows.h>
int main()
{


	HWND wnd = FindWindow(NULL, "�ޱ���.txt- ���±�");
	HDC dc = GetDC(wnd);
	POINT ptText[2] = { {0,50},{200,50} };//MM_TEXTģʽ��ֱ������
	POINT ptLOME[2] = { {0,100},{200,100} };//MM_LOMETRICģʽ��ֱ������
	SetMapMode(dc, MM_LOMETRIC);//����ģʽ
	DPtoLP(dc, ptLOME, 2);//ת����MM_LOMETRIC��Ӧ�������
	while (1)
	{
		MoveToEx(dc, ptLOME[0].x, ptLOME[1].y, NULL);
		LineTo(dc, ptLOME[1].x, ptLOME[1].y);
		SetMapMode(dc, MM_TEXT);//ģʽ�Ļ���
		MoveToEx(dc, ptText[0].x, ptText[1].y, NULL);
		LineTo(dc, ptText[1].x, ptText[1].y);
		Sleep(300);
		SetMapMode(dc, MM_LOMETRIC);//����ģʽ
	}
	return 0;
}


��Ȼ����ת��ȥ��Ҳ��Ȼ����ת����


DPtoLP���ڰ����ص�λת��������ģʽ��λ�����Ĳ�����������Ϊ��λ�ģ�ת����ֵ�ĵ�λ���ǵ�ǰģʽ��Ӧ�ĵ�λ����LPtoDP�����෴���������ĵ�λ���Ե�ǰģʽΪ׼�ģ����ڰ�����ģʽ�µ������ת����MM_TEXTģʽ�µġ���ģʽMM_LOMETRIC���������469�� - 469ת���ɶ�Ӧ���ص�λ����POINT pt = { 469,-469 }; LPtoDP(dc, &pt, 1);//�ǵ�Ҫ����ģʽ��





http://hi.baidu.com/3582077/item/eebe0ae316019bafcf2d4f08


��һ��һʮ����SetViewportOrgEx������ԭ�㣨0��0��ӳ�䵽�豸�����X, Y


�������壺BOOL SetWindowOrgEx(HDC hdc, int X, int Y, LPPOINTlpPoint);


hdc��Ҫӳ����豸�����ģ�X, Y��Ҫӳ������꣬lpPoint�Ǵ���ԭ��ԭ����ӳ������꣬�����ȡ��ΪNULL��


��������һ����䣺������hdc���豸ģʽΪMM_TEXT����ô������������


SetViewportOrgEx(hdc, 200, 200, NULL);


���ڵ�����ͱ�����������ˣ�


�����ӣ�


#include<windows.h>
int main()
{
	HWND wnd = FindWindow(NULL, "�ޱ���.txt - ���±�");
	HDC hdc = GetDC(wnd);
	::SetViewportOrgEx(hdc, 200, 200, NULL);//���������200��200Ϊ����ԭ�����0��0
	while (1)
	{
		Rectangle(hdc, 0, 0, 100, 100);
		Rectangle(hdc, 0, 0, -100, -100);
		Sleep(300);
	}
	return 0;
}


��һ��һʮ�߸�SetWindowOrgEx���豸�����X, Yӳ�䵽����ԭ��0��0


�������壺BOOL SetWindowOrgEx(HDC hdc, int X, int Y, LPPOINTlpPoint);


��SetViewportOrgEx��ӳ�������෴����������Ĳ������Ͳ���SetViewportOrgEx��


�������������


SetWidnowOrgEx(hdc, 200, 200, NULL); ����Ĵ�������ͼ����Ȼ����Ҳ����Ϊ���������������㴰������㡣




��һ��һʮ�˸�SetScrollPos���ù�����λ��


�������壺int
SetScrollPos(
	HWND hWnd,//���������ڴ��ھ��
	int nBar,//���������ͣ�����SetScrollInfo����
	int nPos,//������λ��
	BOOL bRedraw);//�Ƿ��ػ�������


���ӣ��ο�SetScrollInfo���������ӡ�


��һ��һʮ�Ÿ�SetScrollInfo���ù�������Ϣ


�������壺int SetScrollInfo��HWND hWnd;//���������ڵĴ��ھ��


int fnBar,//���������ͣ�SB_VERT��ֱ��������SB_HORZˮƽ������


LPSCROLLINFO lpsi,//������������Ϣ�ṹ�壬������н���


BOOL fRedraw��;//ָ���Ƿ��ػ�������


SetScrollInfo�����ĵ�����������һ��SCROLLINFO�ṹ��ָ�룬���ڸýṹ��Ľ������£�


typedef struct tagSCROLLINFO
{
	UINT cbSize;//ָ��SCROLLINFO�ṹ���С����ֵsizeof(SCROLLINFO)
	UINT fMask;//ָ��nMin-nMax��nPage��nPos��Щ��Ա��Ч,�ֱ��ӦSIF_RANGE��SIF_PAGE��SIF_POS��


	//ΪSIF_DISABLENOSCROLL�������ù�������
	int nMin;//��������Χ��Сֵ
	int nMax;//��������Χ���ֵ
	UINT nPage;//ҳ��С������������С�������
	int nPos;//������λ��
	int nTrackPos;//�����Ա��GetScrollInfo���������á����ڽ��չ�����λ��
} SCROLLINFO, FAR *LPSCROLLINFO;


����Ҫ˵�����ǣ�Ϊ�˱��ⲻ��Ҫ���鷳����������С����������Χ����Ϳɼ������Լ�ʵ�ʴ��ڣ���ͼ������Сһ�¡�


Ҳ����˵����ɼ����ڴ�С��300��ʱ����ô������ҳ��СҲ������300�����ʵ�ʴ��ڴ�С��2000��ʱ����ô��������Χ����0~1999���ֱ�����Сֵ�����ֵ�������������ƶ���ΧҲ����λ������0~1700����Ϊ��������λ����0��ʱ����ʾ������0 - 300����λ����1700��ʱ��պ���ʾ�괰��Ҳ����1700~2000��������λ�����Թ������ϱ�Ϊ׼��


Ҫ����һ�����ھ��й���������ڵ���CreateWindow����ʱ�ڵ�����������ָ�������ˣ���CreateWindow������Ҳ���͹���WS_VSCROLLָ�����ھ��д�ֱ��������񣬶�WS_HSCROLL��ˮƽ��������


���ڹ�������Ϣ�Ľ��ͣ�WM_VSCROLL��ֱ��WM_HSCROLLˮƽ��


�������Ϣ������wParam�����


SB_LINEUP ����������ļ�ͷ��ť��������һ�£�ˮƽ��������Ӧ������ߵİ�ť


SB_LINEDOWN ����������ļ�ͷ��ť���������£�ˮƽ��������Ӧ�����ұߵİ�ť


SB_PAGEUP �����������������ͷ��ť֮������򱻵�����һ�£�ˮƽ�����������֮��


SB_PAGEDOWN �����������������ͷ��ť֮������򱻵�����һ�£�ˮƽ���������ұ�֮�䡣


SB_ENDSCROLL ����뿪�˹�������


SB_THUMBTRACK ����������������


SB_THUMBPOSITION �����������������������̧��ʱ��


���ӣ���ֱ����������Ӧ��


ˮƽ��������ʹ�÷������������ͬС�죬���ԾͲ��ӷŽ����ˣ�ͽ��������������ʹ����һ����ؼ��ĺ���SetWindowOrgEx��ӳ�䴰��ԭ�㣬ʱʱ���ݹ�����λ�����ö�Ӧ�Ĵ���ԭ�㡣�Ա�֤��ǰ��ʾ������ȷ�Ĳ��֡�ÿ���й�����Ϣ������ʱ�򣬶��ػ��˴��ڣ����������ԭʼ���Ժ󽲵�ScrollWIndow����ʱ���иĽ��ģ����б������ֲο���


Programing Windows with MFC��������ݣ�ֻ������������������ʵ�ֵģ������������ȫ����API��ʵ�ֵģ������������ڣ���Ϣ����


�ðɣ��½�һ��WIN32 ���̣������Ǵ��룺


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
	nVPageSize = rect.bottom;//�ɼ����ڸ߶�
	SCROLLINFO si;
	si.cbSize = sizeof(SCROLLINFO);
	si.nMin = 0;
	si.nMax = 1999;//����ʵ�ʴ�С��2000
	si.nPage = nVPageSize;//�ɼ����ڸ߶Ⱥ�ҳ��С����һ��
	si.nPos = 0;
	si.fMask = SIF_ALL;
	::SetScrollInfo(wnd, SB_VERT, &si, FALSE);//���ù�������Ϣ
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
		switch (LOWORD(wParam))//wParam�ĵͶ��ֽڴ洢�й�������Ϣ�롣
		{
		case SB_LINEUP:
			nDelta = -LINESIZE;//���������Ϲ��� LINESIZE �ǹ�����С8
			break;
		case SB_PAGEUP:
			nDelta = -nVPageSize;//����һҳ��Ҳ���ǿɼ����ڸ߶�
			break;
		case SB_THUMBTRACK:
			//wParam�ĸ߶��ֽڴ����й�������λ��
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
	//������λ��
	//������һ�������������λ����5ʱ�������Ϲ���8���㣬���ǲ����ܵģ�����Ҫ���㡣
	nScrollPos = nVScrollPos + nDelta;
	nMaxPos = nViewHeight - nVPageSize;
	if (nScrollPos < 0)
		nDelta = -nVScrollPos;
	else if (nScrollPos > nMaxPos)
		nDelta = nMaxPos - nVScrollPos;
	if (nDelta != 0)
	{
		nVScrollPos += nDelta;
		SetScrollPos(wnd, SB_VERT, nVScrollPos, TRUE);//������λ��
		::InvalidateRect(wnd, NULL, TRUE);//ˢ�´���
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


����Ч����





http://hi.baidu.com/3582077/item/1546021772fbdadebf90423e


��һ�ٶ�ʮ��SQLConnect��������Դ��ODBC API��


��������Դ�����ַ�����һ��������ԴODBC������������һ���ú���SQLConfigDataSource����������˵һ��ODBC�������������˽�һЩ���������Access����һ�����ݿ⣨mdb�ļ�����Ȼ���ODBC��������ѡ��ʼ->����->�������->������->����Դ��ODBC����


���򴰿����£�


�㡰��ӡ���ť�����һ������Դ����ʱ��Ϳ�����SQLConnect������������������Դ�ˡ��㡰��ӡ���ť�������Ĵ������£�




��ΪҪ���ӵ����ݿ��ļ���Access�����ģ�������������ѡ��MisrosoftAccess Driver(*.mdb), �����


(������ӵ���Sql server���ݿ⣬��������ѡ��SQL Server")��


	��������Դȡһ�����ƣ�������Ϣ�����£�




	��ס����Դ�����ƣ�SQLConnect�����ĵڶ���������ľ�������Դ���ơ�����������Ϣ�󣬵����ѡ�񡱰�ť��ѡ�����ݿ��ļ�������ͼ��




	һ·��ȷ������ɣ��Ϳ����ˣ�����������Դ���Ǿ���SQLConnect�������������ɡ�


	SQLConnect�������壺


	SQLRETURN SQL_API SQLConnect(SQLHDBC ConnectionHandle,//����Դ������Ҫ�����ӱ���,����SQLAllocEnv����
		SQLCHAR *ServerName, //����Դ����


		SQLSMALLINT NameLength1,//ServerName�����ĳ��ȣ�ȡSQL_NTS�����ˡ�
		SQLCHAR *UserName, //�û�����û��ΪNULL


		SQLSMALLINT NameLength2,//�û����ַ������ȣ���ȡSQL_NTS��û��Ϊ0
		SQLCHAR *Authentication, //�û�����


		SQLSMALLINT NameLength3);//�û������ַ�������


��������Դ�����ӣ�


#include<windows.h>
#include<sqlext.h>//SQLConnect����ͷ�ļ�
#include<iostream.h>
int main()
{
	HENV henv;//���ݾ�Դ������Ҫ�Ļ�������
	HDBC hdbc;//����Դ������Ҫ�����ӱ���
	RETCODE rcode;
	//�����������
	SQLAllocEnv(&henv);
	//�������Ӿ��
	SQLAllocConnect(henv, &hdbc);
	//���������ǹ̶��ģ���ס�����ˡ�
	//��������Դ
	rcode = ::SQLConnect(hdbc, (PUCHAR)"MyODBC", SQL_NTS, NULL, 0, NULL, 0);
	if (rcode == SQL_SUCCESS)
	{
		cout << "��������Դ�ɹ�!" << endl;
	}
	else
	{
		cout << "����ʧ��!" << endl;
	}


	return 0;
}


�������ݿ⣬Ҳ���ǵ�ͨ����������Դ�ķ���ʵ�֣���SQLDriverConnect������ʹ�� ODBC ����Դ�������ӵģ��Ժ��������������


�ڶ��ٶ�ʮһ��SQLExecDirectִ��SQL���(ODBC API)


�������壺


SQLRETURN SQL_API SQLExecDirect(SQLHSTMT StatementHandle,//�����,SQLAllocStmt�����ɷ���
	SQLCHAR *StatementText,//SQL���


	SQLINTEGER TextLength);//SQL����ַ������ȣ���ΪSQL_NTS


һ��ִ��SQL�������ӣ�


#include<windows.h>
#include<sqlext.h>//SQLConnect����ͷ�ļ�
#include<iostream.h>
int main()
{
	HENV henv;//���ݾ�Դ������Ҫ�Ļ�������
	HDBC hdbc;//����Դ������Ҫ�����ӱ���
	HSTMT hstmt;//������
	RETCODE rcode;
	//�����������
	SQLAllocEnv(&henv);
	//�������Ӿ��
	SQLAllocConnect(henv, &hdbc);
	//���������ǹ̶��ģ���ס�����ˡ�
	//��������Դ
	rcode = ::SQLConnect(hdbc, (PUCHAR)"MyODBC", SQL_NTS, NULL, 0, NULL, 0);
	if (rcode == SQL_SUCCESS)
	{
		cout << "��������Դ�ɹ�!" << endl;
	}
	else
	{
		cout << "����ʧ��!" << endl;
		return 0;
	}


	//������


	::SQLAllocStmt(hdbc, &hstmt);
	LPSTR pszSQL = new char[52];
	//�������ݿ������ΪBookInfo,������BookPrice��BookName�С�
	strcpy(pszSQL, "Update BookInfo set BookPrice=1000 whereBookName='VC++'");
	//ִ��SQL���
	rcode = ::SQLExecDirect(hstmt, (UCHAR *)pszSQL, SQL_NTS);
	if (rcode == SQL_SUCCESS)
	{
		cout << "ִ��SQL���ɹ�!" << endl;
	}
	else
	{
		cout << "ִ��ʧ��!" << endl;
	}
	::SQLDisconnect(hdbc);//�������
	return 0;
}


��һ�ٶ�ʮ����SQLConfigDataSource��������Դ


�������壺


BOOL SQLConfigDataSource(
	HWND hwndParent,//��������Դ�ĸ����ھ����ΪNULL����ʾ��������Դ�Ի���
	WORD fRequest,//ָ��������Դ����ʲô�������������޸ġ�ɾ���ȡ�
	LPCSTR lpszDriver,//��������������Ӧ���洴��������Դ�Ի�����������������ơ�
	LPCSTR lpszAttributes);//���ַ�����˫'\0'��β���������ݸ������ԣ����û�ID�����ݿ��ļ�·��������Դ���Ƶ�,��������'\0'���


fRequest�����Ŀ�ѡֵ��Ϣ���£�


ODBC_ADD_DSN����������Դ��


ODBC_CONFIG_DSN�����û����޸��Ѿ����ڵ�����Դ��


ODBC_REMOVE_DSN��ɾ���Ѿ����ڵ�����Դ��


//ɾ������Դ�Ĵ��룺


SQLConfigDataSource(NULL, ODBC_REMOVE_DSN, "MicrosoftAccess Driver (*.mdb)", "DSN=MyODBC\0\0");


ODBC_ADD_SYS_DSN������ϵͳ����Դ��


ODBC_CONFIG_SYS_DSN�����û����޸��Ѿ����ڵ�ϵͳ����Դ��


ODBC_REMOVE_SYS_DSN��ɾ���Ѿ����ڵ�ϵͳ����Դ��


ODBC_REMOVE_DEFAULT_DSN��ɾ��ȱʡ������Դ��


lpszAttributes�����������������£�


DSN������Դ������


DBQ�����ݿ�·��


DEFAULTDIR�����ݿ�ȱʡ·����Ҳ����DBQֻ��һ���ļ�������ôϵͳҪ���ĸ�Ŀ¼ȥ������ļ�


DESCRIPTION��˵��������㸳ֵ������������Ǹ���Thisis my ODBC"


SERVER������������(SQL Server)


DATABASE�����ݿ����ƣ���master, model


һ����������Դ�����ӣ�


#include<windows.h>
#include<sqlext.h>//SQLConnect����ͷ�ļ�
#include<iostream.h>
#include <odbcinst.h>//SQLConfigDataSource����ͷ�ļ�
int main()
{
	BOOL Result;
	Result = SQLConfigDataSource(NULL, ODBC_ADD_DSN, "Microsoft Access Driver(*.mdb)",
		"DSN=DsAccess\0DBQ=d:\\book.mdb\0\0");
	if (Result == TRUE)
	{
		cout << "����Դ�����ɹ�!" << endl;
	}
	else
	{
		cout << "����ʧ��!" << endl;
	}


	return 0;


}
���Ե�ODBC ����Դ������ȥ�鿴��������û��DsAccess�������Դ��Ȼ����Ҳ����ʾ�ˡ�������


�پ�һ�����ӣ�SQL Server�ģ�


����SQL Server�ﴴ��һ�����ݿ⣬��ΪMyDatabase���������½�һ����BookInfo, �ֶ�BookName, BookPrice, �������Access��һ���������ú����һ�����ݰɣ�BookName��VC++��BookPrice��87���رգ����档


Ȼ�����Sql Server����Դ����������ؼ������Ľ�ͼ��


����Դ���ƣ������������£�




����������20110304 - 1717����������Լ���SqlServer����������������棬Sql Server��ͼ��


֪����ʲô�˰ɡ�����ô��SQLConfigDataSource��������Դ��ʱ�����һ��������SERVER����ľ���������ơ�


����������ѡ���һ���Ҫ�û����û�ID�����룬�Ϳ��Ե�½��ʹ��Ĭ�ϡ�������ѡ��ڶ�������ô���ڵ���SQLConnect��������Դʱ�򣬾�Ҫ����ID�����룬��ѡ���һ��Ļ�������Ҫ��


����Ĭ�ϵ����ݿ�ΪMyDatabase�������ӦSQLConfigDataSource�������һ��������DATABASE


֮�����ñ���Ĭ�ϲ��䣬һֱ����һ����Ȼ�����һ�����ݣ�����ɡ����Ϳ����ˡ���������������Դ�����Ǿ��ô���������һ�¡�


���£�


#include<windows.h>
#include<sqlext.h>//SQLConnect����ͷ�ļ�
#include<iostream.h>
#include <odbcinst.h>//SQLConfigDataSource����ͷ�ļ�
int main()
{
	/*
	//�����ʹ��SQLConfigDataSource��������SQLServer����Դ�Ĵ���
	BOOL Result;
	Result=SQLConfigDataSource(NULL,ODBC_ADD_DSN,"SQL Server",
	"DSN=MySqlServer\0SERVER=20110304-1717\0DATABASE=MyDatabase\0\0");
	if(Result==TRUE)
	{
	cout<<"����Դ�����ɹ�!"<<endl;
	}
	else
	{
	cout<<"����ʧ��!"<<endl;
	}*/




	/*
	HENV henv;//���ݾ�Դ������Ҫ�Ļ�������
	HDBC hdbc;//����Դ������Ҫ�����ӱ���
	HSTMT hstmt;//������
	RETCODE rcode;
	//�����������
	SQLAllocEnv(&henv);


	//�������Ӿ��
	SQLAllocConnect(henv, &hdbc);


	//�����������Դ��ʱ��ָ����ʹ���û�����ID�����뷽ʽ��֤����ô���ӵ�ʱ��
	//Ҳ�����ṩ��ȷ�����룬��֮����Ҫ
	rcode = ::SQLConnect(hdbc, (PUCHAR)"MySqlServer", SQL_NTS, (PUCHAR)"sa", SQL_NTS,
		(PUCHAR)"123456", SQL_NTS);
	if (rcode == SQL_SUCCESS || rcode == SQL_SUCCESS_WITH_INFO)
	{
		cout << "��������Դ�ɹ�!" << endl;
	}
	else
	{
		cout << "����ʧ��!" << endl;
	}


	::SQLAllocStmt(hdbc, &hstmt);
	LPSTR pszSQL = new char[52];
	//�������ݿ������ΪBookInfo,������BookPrice��BookName�С�
	strcpy(pszSQL, "Update BookInfo set BookPrice=1000 whereBookName='VC++'");
	//ִ��SQL���
	rcode = ::SQLExecDirect(hstmt, (UCHAR *)pszSQL, SQL_NTS);
	if (rcode == SQL_SUCCESS)
	{
		cout << "ִ��SQL���ɹ�!" << endl;
	}
	else
	{
		cout << "ִ��ʧ��!" << endl;
	}
	::SQLDisconnect(hdbc);//�������
	return 0;
}


��һ�ٶ�ʮ����SQLDescribeCol��ȡ�����һ�е���Ϣ�����������е��������͵�


�ڽӴ�SQLDescribeCol֮ǰ����һ��������SQLNumResultCols�����������ȡ������еĸ���������һ�ű��м��У�


�������ֻ���������������һ�������洢������


SQLDescribeCol�������壺


SQLRETURN SQLDescribeCol(
	SQLHSTMT StatementHandle,//htstmt���
	SQLUSMALLINT ColumnNumber,//����������ȡ��һ�е���Ϣ����1��ʼ
	SQLCHAR * ColumnName,//�洢����
	SQLSMALLINT BufferLength,//����ColumnName�Ĵ�С��ָ����ڴ棩���ֽ�Ϊ��λ
	SQLSMALLINT * NameLengthPtr,//�洢����ʵ�ʻ�õĳ���
	SQLSMALLINT * DataTypePtr,//�е��������ͣ���SQL_CHAR��SQL_FLOAT
	SQLULEN * ColumnSizePtr,//���ݵĳ��ȣ�������ռ���ֽڣ���int��Ĭ��4��char(10)������10
	SQLSMALLINT * DecimalDigitsPtr,//С����λ��
	SQLSMALLINT * NullablePtr);//�����ԣ������Ƿ����Ϊ�գ�SQL_NO_NULLS�в������ֵ��SQL_NULLABLE����Ϊ��
���ӣ���ȡһ�ű��������������������һ��Student��


#include<windows.h>
#include<sqlext.h>//SQLConnect����ͷ�ļ�
#include<iostream.h>
#include <odbcinst.h>//SQLConfigDataSource����ͷ�ļ�
int main()
{


	HENV henv;//���ݾ�Դ������Ҫ�Ļ�������
	HDBC hdbc;//����Դ������Ҫ�����ӱ���
	HSTMT hstmt;//������
	RETCODE rcode;
	//�����������
	SQLAllocEnv(&henv);


	//�������Ӿ��
	SQLAllocConnect(henv, &hdbc);
	rcode = ::SQLConnect(hdbc, (PUCHAR)"MySqlServer", SQL_NTS, NULL, 0,
		NULL, 0);
	if (rcode == SQL_SUCCESS || rcode == SQL_SUCCESS_WITH_INFO)
	{
		cout << "��������Դ�ɹ�!" << endl;
	}
	else
	{
		cout << "����ʧ��!" << endl;
	}


	::SQLAllocStmt(hdbc, &hstmt);
	LPSTR pszSQL = new char[52];
	//�������ݿ������ΪStudent
	strcpy(pszSQL, "Select * from Student");
	//ִ��SQL���
	rcode = ::SQLExecDirect(hstmt, (UCHAR *)pszSQL, SQL_NTS);
	if (rcode == SQL_SUCCESS)
	{
		cout << "ִ��SQL���ɹ�!" << endl;
		short ColumnCount;//����
		SQLNumResultCols(hstmt, &ColumnCount);
		cout << "����:" << ColumnCount << endl;
		LPSTR pszName = new char[256];//����
		UWORD ColumnIndex;//�е�����
		short BufferLength;//�����ĳ���
		SWORD ColumnType;//�е���������
		UDWORD ColumnSize;//���ݵĳ���
		SWORD DecimalDigits;//С����λ��
		SWORD Nullable;//ֵ�Ƿ����ΪNULL
		cout << "����:" << endl;
		//��ȡÿһ�е���Ϣ��������1��ʼ
		for (ColumnIndex = 1; ColumnIndex <= ColumnCount; ColumnIndex++)
		{
			SQLDescribeCol(hstmt, ColumnIndex, (UCHAR *)pszName, 256, &BufferLength,
				&ColumnType, &ColumnSize, &DecimalDigits, &Nullable);
			//�������
			cout << pszName << " ";
		}
		cout << endl;


	}
	else
	{
		cout << "ִ��ʧ��!" << endl;
	}
	::SQLDisconnect(hdbc);//�������
	return 0;
}


����Ч������ͼ��


��һ�ٶ�ʮ�ĸ�SQLBindCol�󶨱�����һ����


�󶨱�����һ���У��Ϳ��Ի�ö�Ӧ���κ�һ�е����ݣ�����StuName�У��Ҷ���һ���ַ���ָ�����pName���������ڴ棬��pName��


StuName�а󶨺󣬵���SQLFetch�������Ϳ��Ի��StuName��һ�����ݣ�Ĭ���ǵ�һ�У�Ҳ���ǵ�һ��StuName�е����ݣ��ٴε���SQLFetch�Ļ���pName�洢�ľ��ǵڶ���StuName�е����ݣ����ε�����
SQLBindCol�������壺


SQLRETURN SQLBindCol(
	SQLHSTMT StatementHandle,//hstmt���
	SQLUSMALLINT ColumnNumber,//��ȡ��һ�е����ݣ�������
	SQLSMALLINT TargetType,//��������
	SQLPOINTER TargetValuePtr,//�󶨵ı���
	SQLLEN BufferLength,//�洢���ݻ�������С��Ҳ����TargetValuePtr�Ĵ�С
	SQLLEN * StrLen_or_Ind);//ʵ�ʻ�ȡ���ݴ�С�������BufferLength����ÿ�ΰ󶨱��������ݸı䣬�������ֵҲ���Ÿı䣬ָ�����ݴ�С


�����˵һ�µ���������TargetType�������ͣ����������ӦSQLDescribeCol��������������DataTypePtr�����ǵĽ�����һ���ġ�


���⣬��ʹ��������������ͺ���ʵ�����Ͳ�ƥ�䣬Ҳ���ԣ������Զ�ת������Ȼ������һ��ǰ�ᣬ���ǵÿ���ת���������ַ���"12345"ת��������12345��û������ģ����ַ���"1abc"��Ȼ������ת�������͡���������ȡ��ʱ�򣬲���ȥ�˽������й�ϵ�ģ�����������SQL_C_CHAR�����ˣ�Ҳ����SQL_CHAR�������ʾ�ַ�����


���룬���������ͣ������ͣ������������Ͷ��������ַ�������ʽ����ʾ��������Ҳ���Ե�����صĺ�����ת�����ͣ�������Ϳ����ˡ�


���Ը����ʱ��ȥ�˽��������͵����𣬿��Ե�MSDNȥ�飬��ַ���������ű�����ˣ�


http ://msdn.microsoft.com/en-us/library/ms714556(v=VS.85).aspx


���ӣ���ȡ��һ�У��͵ڶ������������ݡ�


#include<windows.h>
#include<sqlext.h>//SQLConnect����ͷ�ļ�
#include<iostream.h>
#include <odbcinst.h>//SQLConfigDataSource����ͷ�ļ�
int main()
{


	HENV henv;//���ݾ�Դ������Ҫ�Ļ�������
	HDBC hdbc;//����Դ������Ҫ�����ӱ���
	HSTMT hstmt;//������
	RETCODE rcode;
	//�����������
	SQLAllocEnv(&henv);


	//�������Ӿ��
	SQLAllocConnect(henv, &hdbc);
	rcode = ::SQLConnect(hdbc, (PUCHAR)"MySqlServer", SQL_NTS, NULL, 0,
		NULL, 0);
	if (rcode == SQL_SUCCESS || rcode == SQL_SUCCESS_WITH_INFO)
	{
		cout << "��������Դ�ɹ�!" << endl;
	}
	else
	{
		cout << "����ʧ��!" << endl;
	}


	::SQLAllocStmt(hdbc, &hstmt);
	LPSTR pszSQL = new char[52];
	//�������ݿ������ΪStudent
	strcpy(pszSQL, "Select * from Student");
	//ִ��SQL���
	rcode = ::SQLExecDirect(hstmt, (UCHAR *)pszSQL, SQL_NTS);
	if (rcode == SQL_SUCCESS)
	{
		cout << "ִ��SQL���ɹ�!" << endl;
		short ColumnCount;//����
		SQLNumResultCols(hstmt, &ColumnCount);
		cout << "����:" << ColumnCount << endl;
		LPSTR pszName = new char[256];//����
		UWORD ColumnIndex;//�е�����
		short BufferLength;//�����ĳ���
		SWORD ColumnType;//�е���������
		UDWORD ColumnSize;//���ݵĳ���
		SWORD DecimalDigits;//С����λ��
		SWORD Nullable;//ֵ�Ƿ����ΪNULL
		cout << "����:" << endl;
		//��ȡÿһ�е���Ϣ��������1��ʼ
		for (ColumnIndex = 1; ColumnIndex <= ColumnCount; ColumnIndex++)
		{
			SQLDescribeCol(hstmt, ColumnIndex, (UCHAR *)pszName, 256, &BufferLength,
				&ColumnType, &ColumnSize, &DecimalDigits, &Nullable);
			//�������
			cout << pszName << " ";
		}
		cout << endl;
		char *pStuNo = new char[256];//�󶨵ı���,ѧ��
		char *pStuName = new char[256];//�󶨵ı���,ѧ������
		long StuNolen;//ʵ�ʻ�ȡ���ݵĴ�С
		long StuNamelen;
		//�󶨱���
		SQLBindCol(hstmt, 1, SQL_C_CHAR, pStuNo, 256, &StuNolen);//��һ��
		SQLBindCol(hstmt, 2, SQL_C_CHAR, pStuName, 256, &StuNamelen);//�ڶ���
		rcode = SQLFetch(hstmt);//��ȡ����
		while (rcode == SQL_ROW_SUCCESS || rcode == SQL_ROW_SUCCESS_WITH_INFO)
		{
			cout << pStuNo << " " << pStuName << endl;
			rcode = SQLFetch(hstmt);//��ȡ��һ������
		}
		SQLCancel(hstmt);
	}
	else
	{
		cout << "ִ��ʧ��!" << endl;
	}


	::SQLDisconnect(hdbc);//�������
	return 0;
}


����Ч����ͼ��





http://hi.baidu.com/3582077/item/08b15d260bc4bf3194f62b21


��һ�ٶ�ʮ���SQLDriverConnect�������ݿ�
�������壺
SQLRETURN SQLDriverConnect(
	SQLHDBC ConnectionHandle,//hdbc���
	SQLHWND WindowHandle,//���ھ��������ʾ����ΪNULL
	SQLCHAR * InConnectionString,//�����ַ���������SQLConfigDataSource���������һ������
	SQLSMALLINT StringLength1,//InConnectionString��������С
	SQLCHAR * OutConnectionString,//�ò�������������ϸ��Ϣ��
	SQLSMALLINT BufferLength,//OutConnectionString��������С
	SQLSMALLINT * StringLength2Ptr,//OutConnectionStringʵ�ʴ�С�����պ�
	SQLUSMALLINT DriverCompletion);//�Ƿ���ʾ���Ӵ��ڣ�SQL_DRIVER_NOPROMPT����ʾ��


SQLDriverConnect���SQLConnect����������ǿ����࣬������ֱ���������ݿ�����������Ҫͨ������Դ����Ȼ��Ҳ������������Դ��SQLDriverConnect��ȫ�������SQLConnect������


��ô��������Դ��ʱ�������ҪID�����룬��Щ��Ϣ���������أ�����InConnectionString�����ַ������Ӧ����������


UID��PWD����������Ľ��Ϳ��Բο�SQLConfigDataSource���������һ��������


SQLDriverConnect������InConnectionString���˼���������(��֮SQLConfigDataSource���������һ����������ǰ��UID��PWD������������һ����DRIVER�����ָ���������ơ�


	SQLDriverConnectӦ�����ӣ�


#include<windows.h>
#include<sqlext.h>//SQLConnect����ͷ�ļ�
#include<iostream.h>
#include <odbcinst.h>//SQLConfigDataSource����ͷ�ļ�
	int main()
{


	HENV henv;//���ݾ�Դ������Ҫ�Ļ�������
	HDBC hdbc;//����Դ������Ҫ�����ӱ���


	RETCODE rcode;
	//��������Դ,�������÷ֺŸ���������Ҫ�ʺ�������֤�Ļ�����������Դ������
	SQLCHAR ConnStr[256] = { "DSN=MySqlServer;UID=sa;PWD=123456" };


	//ֱ������Access���ݿ�
	//SQLCHAR ConnStr[256]={"DBQ=d:\\book.mdb;DRIVER=Microsoft Access Driver(*.mdb)"};


	//ֱ������SQL Server
	//SQLCHARConnStr[256]={"SERVER=20110304-1717;DATABASE=MyDatabase;DRIVER=SQLServer"};
	SQLCHAR OutConnStr[256];
	short OutConnStrLen;
	//�����������
	SQLAllocEnv(&henv);
	HWND desktopHandle = GetDesktopWindow();
	//�������Ӿ��
	SQLAllocConnect(henv, &hdbc);
	rcode = ::SQLDriverConnect(hdbc, NULL, ConnStr,
		SQL_NTS,
		OutConnStr, 256, &OutConnStrLen, SQL_DRIVER_NOPROMPT);
	if (rcode == SQL_SUCCESS || rcode == SQL_SUCCESS_WITH_INFO)
	{
		cout << "���ӳɹ�!" << endl;
		cout << OutConnStr << '\t' << OutConnStrLen << endl;
	}
	else
	{
		cout << "����ʧ��!" << endl;
	}


	::SQLDisconnect(hdbc);//�������
	return 0;
}


��һ�ٶ�ʮ���SQLFetchScroll�����������


ǰ���ᵽ��SQLFetch������ֻ����һ�������ƶ������ǵ��α��ڵ�һ�е�ʱ�򣬵���SQLFetch������õ��ǵڶ��е����ݣ������ı�������


��SQLFetchScroll����������һ���ƶ�����������һ���ƶ���Ҳ�ܻ�ȡ�ض��е����ݡ���


�������壺SQLRETURN SQLFetchScroll(
	SQLHSTMT StatementHandle,//hstmt���
	SQLSMALLINT FetchOrientation,//��������ǰ�ƶ�����������ƶ��������ض��С�
	SQLLEN FetchOffset);//�����ض��У�ָ���ƶ������У�Ҳ�ͻ�ȡ�������ݡ�������ǰ�����壬Ϊ0


�ڶ�������FetchOrientation������ȡֵ��


SQL_FETCH_NEXT//��ȡ��һ��


SQL_FETCH_PRIOR//��ȡ��һ��


SQL_FETCH_FIRST //��ȡ����


SQL_FETCH_LAST //��ȡ���һ��


SQL_FETCH_ABSOLUTE //������ָ��ȡ��һ�У�FetchOffsetָ������


SQL_FETCH_RELATIVE //������ָ��ȡ��һ�У�λ��Ϊ��ԡ��統ǰ�ڵڶ��У�FetchOffsetΪ2����ô��ȡ���ǵ�4�С�


���ֱ�ӵ���SQLFetchScroll�������ᷢ�ֳ���SQL_FETCH_PRIOR��SQL_FETCH_NEXT������Ч�⣬������������Ч����ʲôԭ���ء���������hstmt��������ɵģ�Ĭ�����Թ涨�α�ֻ����ǰ�ƶ���Ҳ����SQL_CURSOR_FORWARD_ONLY��


������ǰһ�У����ж����Ҹ����ˣ�FORWARD����ǰ����˼��NEXT����һ�е���˼������û��ͳһ�Ľз�����㲻���ף�


����ֻҪ��HSTMT��SQL_ATTR_CURSOR_TYPE�α��������óɾ�̬�ľ����ˡ�Ҳ����SQL_CURSOR_STATIC��


��SQLSetStmtAttr�����������á�����������Ե�MSDN��顣������ֻ��������һ�����Ծ����ˣ������������⡣���õ�������£�


SQLSetStmtAttr(hstmt, SQL_ATTR_CURSOR_TYPE, (void*)SQL_CURSOR_STATIC, SQL_IS_INTEGER);


������һ�������ӣ���ȡ�ض��е����ݡ�


#include<windows.h>
#include<sqlext.h>//SQLConnect����ͷ�ļ�
#include<iostream.h>
#include <odbcinst.h>//SQLConfigDataSource����ͷ�ļ�
int main()
{


	HENV henv;//���ݾ�Դ������Ҫ�Ļ�������
	HDBC hdbc;//����Դ������Ҫ�����ӱ���
	HSTMT hstmt;//������
	RETCODE rcode;
	//�����������
	SQLAllocEnv(&henv);


	//�������Ӿ��
	SQLAllocConnect(henv, &hdbc);
	rcode = ::SQLConnect(hdbc, (PUCHAR)"MySqlServer", SQL_NTS, NULL, 0,
		NULL, 0);
	if (rcode == SQL_SUCCESS || rcode == SQL_SUCCESS_WITH_INFO)
	{
		cout << "��������Դ�ɹ�!" << endl;
	}
	else
	{
		cout << "����ʧ��!" << endl;
	}


	::SQLAllocStmt(hdbc, &hstmt);
	LPSTR pszSQL = new char[52];
	//�������ݿ������ΪStudent
	strcpy(pszSQL, "Select * from Student");
	//ִ��SQL���
	//���þ�̬�α�
	SQLSetStmtAttr(hstmt, SQL_ATTR_CURSOR_TYPE, (void *)SQL_CURSOR_STATIC, SQL_IS_INTEGER);
	rcode = ::SQLExecDirect(hstmt, (UCHAR *)pszSQL, SQL_NTS);
	if (rcode == SQL_SUCCESS)
	{
		cout << "ִ��SQL���ɹ�!" << endl;
		char *pStuNo = new char[256];//�󶨵ı���,ѧ��
		long StuNolen;//ʵ�ʻ�ȡ���ݵĴ�С
		//�󶨱���
		SQLBindCol(hstmt, 1, SQL_C_CHAR, pStuNo, 256, &StuNolen);//��һ��
		//��ȡ�ڶ��е�ѧ��,ѧ����ð�˳���ţ����һ��001���ڶ���002�������ò鿴�����ʱ������ֵ�Щ��
		rcode = SQLFetchScroll(hstmt, SQL_FETCH_ABSOLUTE, 2);
		cout << pStuNo << endl;
		SQLCancel(hstmt);
	}
	else
	{
		cout << "ִ��ʧ��!" << endl;
	}


	::SQLDisconnect(hdbc);//�������
	return 0;


}
*/ 