#include "MultiLabel.h"



MultiLabel::MultiLabel()
{

}


MultiLabel::~MultiLabel()
{
}

Mat MultiLabel::mergedGrayLabel()
{
	Mat mergedGray = Mat::zeros(currentGCMask.size(),CV_8UC1);
	vector<multiMask>::iterator iter = maskVec.begin();
	for (; iter != maskVec.end(); ++iter) {
		mergedGray.setTo(1, (*iter).mask);
	}
	
	return mergedGray;
}

Mat MultiLabel::mergedColorLabel() 
{
	Mat mergedGray = mergedGrayLabel();
	Mat mergedColor = Mat::zeros(mergedGray.size(), CV_8UC3);

	Mat img = imread(inputImgName.toStdString());
	Mat mergedGrayN = Mat::ones(mergedGray.size(), CV_8UC1);
	mergedGrayN.setTo(0, mergedGray);
	mergedColor = img.setTo(0,mergedGrayN);
	return mergedColor;
}

Mat MultiLabel::currentGrayLabel()
{
	Mat currentGray = Mat::zeros(currentGCMask.size(), CV_8UC1);
	currentGray.setTo(1, currentMask);
	return currentGray;
}
Mat MultiLabel::currentColorLabel()
{
	//�Ƚ����Ҷȱ�ǩͼ��Ȼ���ͼ
	Mat currentGray = currentGrayLabel();
	Mat currentColor = Mat::zeros(currentGray.size(), CV_8UC3);

	Mat img = imread(inputImgName.toStdString());
	currentColor = img.setTo(labelColor, currentGray);
	return currentColor;
}

void MultiLabel::refresh()
{
	//currentGCMask = 0;
	//currentMask = 0;
	currentGCMask.setTo(0);
	currentMask.setTo(0);
	currentBgdModel.release();
	currentFgdModel.release();
}

void MultiLabel::clearImg()
{
	//ɾȥͼ������֣���ʾ����û��ͼ��
	inputImgName.clear();
	//�´�ͼƬ������Ҫ�ͷţ����ܽ���Ϊ0����Ϊ�ߴ緢���˱仯
	currentGCMask.release();
	currentMask.release();
	currentBgdModel.release();
	currentFgdModel.release();
	maskVec.clear();
}
void MultiLabel::clearLabel()
{
	//inputLabelName.clear();
	//currentLabel = 1;
	//labelName.clear();
	//labelNum.clear();
	//labelColor.clear();
}
