#include "GameObjectWidget.h"

// bool GameObjectWidget::isSelected() const { return gameObject->getSelected(); }

// void GameObjectWidget::setSelected(bool Selected) { gameObject->setSelected(Selected); }

void GameObjectWidget::formLayoutAddRow(const QString &rowName, QWidget *widget) { formlayout->addRow(rowName, widget); }
void GameObjectWidget::formLayoutAddRow(QWidget *label, QWidget *field) { formlayout->addRow(label, field); }

GameObjectWidget::GameObjectWidget(AbilityTreeData *absData, QWidget *parent) : QWidget(parent)
{
    this->absData = absData;

    int height = 50;
    int width = 300;
    int headerTextSize = 12;

    setMaximumWidth(width);
    setMinimumWidth(width);
    setMaximumHeight(height);
    setMinimumHeight(height);

    vbox = new QVBoxLayout(this);
    headerWidget = new QWidget(this);
    auto headerLayout = new QHBoxLayout(headerWidget);
    headerLabel = new QLabel("", headerWidget);
    headerLabel->setTextFormat(Qt::RichText);
    headerLabel->setAlignment(Qt::AlignCenter);
    headerLabel->setText("<b>" + absData->getAbilityName() + " Value: " + QString::number(absData->getAbilityValue()) + " Price: " + QString::number(absData->getPrice()) + " Click To Buy" + "</b>");
    QFont font;
    font.setPointSize(headerTextSize);
    headerLabel->setFont(font);

    headerLayout->setContentsMargins(0, 6, 0, 0);
    //    headerLayout->setMargin(0);

    headerLabel->setTextFormat(Qt::RichText);
    headerLayout->addWidget(headerLabel);

    headerWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    vbox->addWidget(headerWidget);
}

GameObjectWidget *GameObjectWidget::createWidget(AbilityTreeData *absData, QWidget *parent)
{
    if (!absData) return Q_NULLPTR;


    return new GameObjectWidget(absData, parent);
}

void GameObjectWidget::paintEvent(QPaintEvent * /*event*/)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addRoundedRect(QRectF(0, 0, width(), height()), 5, 5);

    painter.setPen(QColor(0, 0, 0));

    if (!absData) return;

    if (absData->isUnlocked())
    {
        painter.fillPath(path, QColor("#BAB5B5"));
    }
    else
    {
        painter.fillPath(path, QColor("#C96238"));
    }
}

void GameObjectWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    // Wenn nur über body Click selektiert werden soll z.B. für Drag&Drop
    //    qDebug() << "Formlayout: " << formlayout->geometry();
    //    QRect geo = formlayout->geometry();
    //    geo.setHeight(formlayout->geometry().height() - 35);
    //    if (!geo.contains(event->pos()))
    //    {


    clicked(absData);

    updateWidget();
}

void GameObjectWidget::updateWidget()
{
    if (!absData) return;
    update();
}
