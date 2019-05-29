#include "chatwindow.h"
#include "MyTextEdit.h"

ChatWindow::ChatWindow(const User& u, ChatSession& s, QWidget *parent) : QWidget(parent), user{ u }, chatSession{ s }
{
	ui.setupUi(this);
	this->ui.messageListWidget->setIconSize(QSize(70, 70));
	this->ui.messageListWidget->setWordWrap(true);
	this->setWindowTitle(QString::fromStdString(this->user.getName()));

	// register the observer

	QObject::connect(this->ui.sendButton, &QPushButton::clicked, this, [&]() { this->sendMessage();	});

}

ChatWindow::~ChatWindow()
{

}

void ChatWindow::update()
{
	// clear window

	// get the messages
	std::vector<std::pair<User, Message>> messages;
	for (auto& msg : messages)
	{
		QPixmap pixmap{ QString::fromStdString(msg.first.getUniqueUserName() + ".jpg") };
		QIcon icon{ pixmap };
		QListWidgetItem* item = new QListWidgetItem{ icon, "" };
		item->setToolTip(QString::fromStdString(msg.second.getTimestampAsString()));

		if (msg.first == this->user)
		{
			item->setText(QString::fromStdString(msg.second.getMessageString()));
			item->setForeground(QBrush{ QColor{ Qt::darkMagenta } });
			item->setTextAlignment(Qt::AlignRight);
		}
		else
		{

		}

	}
}

void ChatWindow::sendMessage()
{
	// get the message
	

	// add the message to the chat session
	

	// clear the text endit

}
