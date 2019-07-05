#include "ImgCut.h"

ImgCut::ImgCut(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.graphicsView->resetTransform();
	ui.graphicsView->setScene(scene);
	ui.spinBoxBrush->setValue(5);
	//���ð�ť���ɱ�����
	buttonsOff();

	//���Ӳ˵����������Ͳ˵���Ϣ
	connect(ui.actionOpenImg, &QAction::triggered, this, &ImgCut::OpenImgAction);
	connect(ui.actionCloseImg, &QAction::triggered, this, &ImgCut::CloseImgAction);
	connect(ui.actionSaveAsRGB, &QAction::triggered, this, &ImgCut::SaveAsRGBAction);
	connect(ui.actionHelp, &QAction::triggered, this, &ImgCut::HelpAction);
	connect(ui.actionContact, &QAction::triggered, this, &ImgCut::ContactAction);
}
void ImgCut::buttonsOff()
{
	//���ð�ť���ɱ�����
	ui.radioButtonBrush->setCheckable(false);
	ui.radioButtonROI->setCheckable(false);
	ui.checkBoxClean->setCheckable(false);

	ui.toolButtonGrabCut->blockSignals(true);
	//ui.toolButtonSetLabel->blockSignals(true);
	ui.toolButtonFinish->blockSignals(true);
}
//-----------------------------������------------------------
void ImgCut::OpenImgAction() {

	//��ȡͼ���ļ��������ص�scene
	multiLabel.inputImgName = QFileDialog::getOpenFileName(this, "Open Input \
		Image", QDir::currentPath(), "Images(*.jpg *.png *.bmp)");
	if (QFile::exists(multiLabel.inputImgName)) {
		QPixmap orinImg;
		if (orinImg.load(multiLabel.inputImgName)) {
			scene->clear();
			//���ó����߽�
			QPointF topLeft(0, 0);
			QPointF bottomRight(orinImg.width(), orinImg.height());
			scene->setBounding(topLeft, bottomRight);
			//���ó����Ĵ�С
			//ע�⣬Ĭ�������Qt�Ǳ���������ӹ���item�����ߴ���Ϊ�����ߴ磬��ᵼ�¹���
			QRectF sceneRect(topLeft, bottomRight);
			scene->setSceneRect(sceneRect);
			scene->addPixmap(orinImg);

			//���ÿ���
			ui.radioButtonBrush->setCheckable(true);
			ui.radioButtonROI->setCheckable(true);
			ui.checkBoxClean->setCheckable(true);
			//ui.toolButtonSetLabel->blockSignals(false);
		}

		else {

		}
	}

}

void ImgCut::CloseImgAction() {
	//���scene
	scene->clear();
	multiLabel.clearImg();
	//��0��������
	interacCount = 0;
	//���ÿ���
	buttonsOff();
}

void ImgCut::SaveAsRGBAction()
{
	QString outputLabelName = QFileDialog::getSaveFileName(this,
		"Select Output Image", QDir::currentPath(),
		"*.jpg;;*.png;;*.bmp");
	if (!outputLabelName.isEmpty()) {
		Mat outputColorLabel = multiLabel.mergedColorLabel();
		//cvtColor(outputColorLabel, outputColorLabel, CV_BGR2RGB);
		imwrite(outputLabelName.toStdString(), outputColorLabel);
		QString notice = "Save label successfully as 3channel RGB.";
		QMessageBox::about(this, "Notice", notice);
	}
}

void ImgCut::HelpAction()
{
	QString line1 = "To learn how to use ImgCut, please refer to README.txt\n";
	QMessageBox::about(this, "Help", line1);
}
void ImgCut::ContactAction()
{
	QString notice = "Author's email: yuanyouxu@zju.edu.cn\n";
	QMessageBox::about(this, "Contact", notice);
}

void ImgCut::closeEvent(QCloseEvent *event)
{
	int result = QMessageBox::warning(this, "Exit",
		"Are you sure to close ImgCut?",
		QMessageBox::Yes, QMessageBox::No);
	if (result == QMessageBox::Yes) {
		event->accept();
	}
	else {
		event->ignore();
	}
}
//-----------------------��ť��----------------------

void ImgCut::on_radioButtonROI_clicked()
{
	if (ui.radioButtonROI->isChecked()) {
		//ÿ�ΰ��°�ť�����¿�ʼ����
		clearType(QGraphicsItem::UserType);
		roi = new ROI(scene->width(), scene->height());
		scene->addItem(roi);
		roi->setROI(true);
		scene->setBrush(false, false);

		//if (multiLabel.currentLabel != -1)
		ui.toolButtonGrabCut->blockSignals(false);
	}
}
void ImgCut::on_radioButtonBrush_clicked() {
	if (ui.radioButtonBrush->isChecked()) {
		//clearType(QGraphicsLineItem::Type);
		roi->setROI(false);
		scene->setBrush(true, false);
	}
}
void ImgCut::on_checkBoxClean_clicked() {
	if (ui.radioButtonBrush->isChecked()) {
		if (ui.checkBoxClean->isChecked())
			scene->setBrush(true, true);
		else
			scene->setBrush(true, false);
	}
}

void ImgCut::on_toolButtonFinish_pressed()
{
	multiMask tmp;
	//tmp.labelNum = multiLabel.currentLabel;
	//multiLabel.currentLabel++;
	//������Բ����õȺţ��Ⱥ��ǹ���һ��ͼ��
	//һ��Ҫ���Ƶ�����һ�ݳ���
	//tmp.mask = multiLabel.currentMask;
	multiLabel.currentMask.copyTo(tmp.mask);
	//��ע˳������ǰ���󱳾������Ժ�����Ӧ�ò���ǰ������Ǻ���
	//multiLabel.maskVec.push_back(tmp);
	multiLabel.maskVec.insert(multiLabel.maskVec.begin(), tmp);


	QString notice = "The latest cut has been saved.\n";
	QMessageBox::about(this, "Notice", notice);
	multiLabel.refresh();

	//ÿ�������µ�label������ճ��������¼���ͼ��
	if (QFile::exists(multiLabel.inputImgName)) {
		QPixmap orinImg;
		if (orinImg.load(multiLabel.inputImgName)) {
			scene->clear();
			scene->addPixmap(orinImg);

		}
	}
	//ÿ��Ҫ��GCmask��0������roi��С�仯ʱ���������ۼ�
	multiLabel.currentGCMask.setTo(0);
	//��0��������
	interacCount = 0;

	//���ÿ���
	buttonsOff();
	ui.radioButtonBrush->setCheckable(true);
	ui.radioButtonROI->setCheckable(true);
	ui.checkBoxClean->setCheckable(true);
}

void ImgCut::on_toolButtonBrushSize_pressed()
{
	int brushSize = ui.spinBoxBrush->value();
	if (brushSize > 0 && brushSize < 50) {
		scene->setBrushSize(brushSize);
		QString notice = "Brush size has been set to " + QString::number(brushSize);
		QMessageBox::about(this, "Notice", notice);
	}
}

//-----------------���Ĳ��֣�grabcut--------------
Mat groupToMask(QGraphicsScene *scene, int type)
{
	QList<QGraphicsItem*> items = scene->items();
	foreach(QGraphicsItem *item, items) {
		if (item->type() != type) {
			item->setOpacity(0);
		}
	}
	QGraphicsItemGroup *group = scene->createItemGroup(items);
	QPixmap map = itemToQPixmap(group);
	//��ϳ�group�����Ҫ���٣���Ȼ�����
	scene->destroyItemGroup(group);
	Mat mat = cvert::QPixmapToCvMat(map);
	foreach(QGraphicsItem *item, items) {
		if (item->type() != type) {
			item->setOpacity(1);
		}
	}
	Mat mask(mat.size(), CV_8UC1);
	cvtColor(mat, mask, CV_BGR2GRAY);
	threshold(mask, mask, 0.5, 1, THRESH_BINARY);
	return mask;
}

void ImgCut::on_toolButtonGrabCut_pressed()
{
	try {
		//����ͼ��
		Mat cvImg = imread(multiLabel.inputImgName.toStdString());
		//����ROI���Σ��������ľ���СһȦ
		//Rect cvRect(roi->getX() + 1, roi->getY() + 1,
		//	roi->getWidth() - 2, roi->getHeight() - 2);
		Rect cvRect(int(roi->getX()), int(roi->getY()),
			int(roi->getWidth()) + 1, int(roi->getHeight()) + 1);

		//ǰ���뱳����mask ------------����Ƿ�Ϊ��
		Mat fgMask = groupToMask(scene, QGraphicsLineItem::Type);
		Mat bgMask = groupToMask(scene, QGraphicsEllipseItem::Type);

		//��roi���Σ�ǰ��������mask�ں�
		//���û���¹涨roi������ԭ���Ļ��������ǰ���ͱ���
		//������Ҫ���»���ǰ���ͱ���
		if (multiLabel.currentGCMask.empty()) {
			multiLabel.currentGCMask = Mat::zeros(cvImg.size(), CV_8UC1);
		}

		if (cvRect == multiLabel.currentRect) {

			multiLabel.currentGCMask(cvRect).setTo(GC_FGD, fgMask(cvRect));	//ȷ����ǰ��
			multiLabel.currentGCMask(cvRect).setTo(GC_BGD, bgMask(cvRect));	//ȷ���ı���
		}
		else {
			multiLabel.currentRect = cvRect;
			multiLabel.currentGCMask(cvRect) = GC_PR_FGD; //���ܵ�ǰ��
			multiLabel.currentGCMask(cvRect).setTo(GC_FGD, fgMask(cvRect));	//ȷ����ǰ��
			multiLabel.currentGCMask(cvRect).setTo(GC_BGD, bgMask(cvRect));	//ȷ���ı���
		}


		//�м����
		Mat bgdModel, fgdModel;
		//ȷ����������
		int iterCount = 4;
		//��ʱ
		clock_t start = clock();
		//�ָ�
		if (cutMode == NORMAL_CUT) {
			if (interacCount == 0) {
				grabCut(cvImg, multiLabel.currentGCMask, cvRect,
					bgdModel, fgdModel,
					iterCount, GC_INIT_WITH_MASK);
				multiLabel.currentBgdModel = bgdModel.clone();
				multiLabel.currentFgdModel = fgdModel.clone();
			}

			else
				grabCut(cvImg, multiLabel.currentGCMask, cvRect,
					//bgdModel, fgdModel,
					multiLabel.currentBgdModel, multiLabel.currentFgdModel,
					iterCount, GC_EVAL);
		}
		clock_t end = clock();
		qDebug() << interacCount << ": " << (double)(end - start) / CLOCKS_PER_SEC
			<< "second";
		interacCount++;
		//myGrabCut(cvImg, cvRect, iterCount);
		//grabCut(cvImg(cvRect), multiLabel.currentGCMask(cvRect), cvRect, bgdModel, fgdModel,
		//	iterCount, GC_INIT_WITH_MASK);


		//����ǿ���ǰ����ȷ��ǰ���Ĳ���
		Mat resultMaskFGD = Mat::zeros(cvImg.size(), CV_8UC1);
		Mat resultMaskPRFGD = Mat::zeros(cvImg.size(), CV_8UC1);
		compare(multiLabel.currentGCMask, GC_FGD, resultMaskFGD, CMP_EQ);
		compare(multiLabel.currentGCMask, GC_PR_FGD, resultMaskPRFGD, CMP_EQ);
		multiLabel.currentMask = resultMaskFGD | resultMaskPRFGD;

		Mat mix = cvImg * 0.5 + multiLabel.currentColorLabel()*0.5;
		QPixmap result = cvert::cvMatToQPixmap(mix);

		clearType(QGraphicsLineItem::Type);
		clearType(QGraphicsEllipseItem::Type);
		scene->addPixmap(result);

		//���ÿ���
		ui.toolButtonFinish->blockSignals(false);
	}

	catch (...) {
		QString notice1 = "(o w o)? GrabCut failed!\n";
		QString notice2 = "Please set your label or ROI and try again.\n";
		QMessageBox::about(this, "Fail", notice1 + notice2);
	}
}

void ImgCut::clearType(int type)
{
	QList<QGraphicsItem*> items = scene->items();
	foreach(QGraphicsItem *item, items) {
		if (item->type() == type) {
			scene->removeItem(item);
		}
	}
}

QPixmap itemToQPixmap(QGraphicsItem *item)
{
	QRectF r = item->boundingRect();
	QPixmap pixmap(r.width(), r.height());
	//QPixmap pixmap(item->boundingRect().size().toSize());
	pixmap.fill(QColor(0, 0, 0, 0));
	QPainter painter(&pixmap);
	//painter.setBrush(QBrush(QColor(0, 0, 0, 0)));
	painter.drawRect(r);
	item->scene()->render(&painter, QRectF(), item->sceneBoundingRect());
	painter.end();
	return pixmap;
}
