#include "Player.h"
#include <QMediaPlayer>
#include <QAudioOutput>

Player::Player() {
    mediaPlayerWhite.resize(7);
    audioOutputWhite.resize(7);
    for(int ii = 0; ii < 7; ++ii) {
        mediaPlayerWhite[ii] = new QMediaPlayer;
        audioOutputWhite[ii] = new QAudioOutput;

        mediaPlayerWhite[ii]->setAudioOutput(audioOutputWhite[ii]);
        audioOutputWhite[ii]->setVolume(100);
    }

    mediaPlayerBlack.resize(7);
    audioOutputBlack.resize(7);
    for(int ii = 0; ii < 7; ++ii) {
        // if(ii == 0 || ii == 3) continue;
        mediaPlayerBlack[ii] = new QMediaPlayer;
        audioOutputBlack[ii] = new QAudioOutput;

        mediaPlayerBlack[ii]->setAudioOutput(audioOutputBlack[ii]);
        audioOutputBlack[ii]->setVolume(100);

        QObject::connect(mediaPlayerBlack[ii], &QMediaPlayer::errorOccurred, [](QMediaPlayer::Error error) {
            qDebug() << "Error occurred:" << error;
        });
    }
}

Player::~Player()
{

}

void Player::whitePressed(int key) {
    char a = key;
    if((a < 'A') || (a > 'G')) return;

    // media = new QMediaPlayer;
    // output = new QAudioOutput;

    // media->setAudioOutput(output);
    // output->setVolume(59);

    // media->setSource(QUrl(QString("qrc:/sounds/%1.wav").arg(a)));
    // media->play();

    mediaPlayerWhite[key - 'A']->setSource(QUrl(QString("qrc:/sounds/%1.wav").arg(a)));
    mediaPlayerWhite[key - 'A']->play();
}

void Player::blackPressed(int key) {
    char a = key;
    // if((a < 'A') || (a > 'G')) return;
    qDebug() << a << key - 'A';
    mediaPlayerBlack[0]->setSource(QUrl(QString("qrc:/sounds/%11.wav").arg(a)));
    mediaPlayerBlack[0]->play();
}
