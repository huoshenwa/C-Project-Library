#include <stdio.h>
#include <easyx.h> //easyx��ͷ�ļ�
#include <mmsystem.h>   // ϵͳ��ý��ͷ�ļ�
#pragma comment(lib,"winmm.lib")
int main() {
	// ����һ�����ڣ���ȣ��߶ȣ�
	initgraph(800,450);
	// ������������ֵ��ֺź�����(�ֺţ�����Ӧ[0],����)
	settextstyle(72,0,"����");
	// ����������ɫ
	settextcolor(RGB(255, 149, 240));
	//�ڴ���������ı���x��,y�ᣬ���ݣ�
	outtextxy(20, 100, "��ɳ������");
	//�������
	//cleardevice();

	// �������� ���� ���� �ر�)
	/*mciSendString("open ������.mp3", 0, 0, 0);
	mciSendString("play ������.mp3", 0, 0, 0);*/
	//mciSendString("close ������.mp3", 0, 0, 0);
	
	//����ͼƬ  1.����  2.��ʼ��  3.��Ⱦ���
	IMAGE bkimg;  // ����
	loadimage(&bkimg, "ab.jpg");  // ��ʼ��
	putimage(0, 0, &bkimg);  // ��Ⱦ���

	// �����������ͼ���
	
	ExMessage m;
	while (1) {
		//peekmessage����Ϣ�����С�͵����һ��������Ϣ�����/���̣����������Ƴ���
		peekmessage(&m, EX_MOUSE | EX_KEY); //�������|������Ϣ�� 
		if (m.message == WM_KEYDOWN) // ������
		{
			if (m.vkcode == 'F') {
				mciSendString("close ������.mp3", 0, 0, 0); // ��ǿ�ƹر�
				mciSendString("open ������.mp3", 0, 0, 0);
				mciSendString("play ������.mp3", 0, 0, 0);
			}
			if (m.vkcode == 'C')
			{
				mciSendString("close ������.mp3", 0, 0, 0);
			}
		}
	}
	return 0;
}