#include <stdio.h>
#include <easyx.h> //easyx的头文件
#include <mmsystem.h>   // 系统多媒体头文件
#pragma comment(lib,"winmm.lib")
int main() {
	// 创建一个窗口（宽度，高度）
	initgraph(800,450);
	// 更改输出的文字的字号和字体(字号，自适应[0],字体)
	settextstyle(72,0,"隶书");
	// 设置字体颜色
	settextcolor(RGB(255, 149, 240));
	//在窗口中输出文本（x轴,y轴，内容）
	outtextxy(20, 100, "长沙吴彦祖");
	//清空字体
	//cleardevice();

	// 导入音乐 （打开 播放 关闭)
	/*mciSendString("open 土拨鼠.mp3", 0, 0, 0);
	mciSendString("play 土拨鼠.mp3", 0, 0, 0);*/
	//mciSendString("close 土拨鼠.mp3", 0, 0, 0);
	
	//导入图片  1.定义  2.初始化  3.渲染输出
	IMAGE bkimg;  // 定义
	loadimage(&bkimg, "ab.jpg");  // 初始化
	putimage(0, 0, &bkimg);  // 渲染输出

	// 监听控制鼠标和键盘
	
	ExMessage m;
	while (1) {
		//peekmessage从消息队列中“偷看”一条输入消息（鼠标/键盘），但不会移除它
		peekmessage(&m, EX_MOUSE | EX_KEY); //监听鼠标|键盘消息， 
		if (m.message == WM_KEYDOWN) // 按键盘
		{
			if (m.vkcode == 'F') {
				mciSendString("close 土拨鼠.mp3", 0, 0, 0); // 先强制关闭
				mciSendString("open 土拨鼠.mp3", 0, 0, 0);
				mciSendString("play 土拨鼠.mp3", 0, 0, 0);
			}
			if (m.vkcode == 'C')
			{
				mciSendString("close 土拨鼠.mp3", 0, 0, 0);
			}
		}
	}
	return 0;
}