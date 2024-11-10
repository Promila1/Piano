#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
class QMediaPlayer;
class QAudioOutput;


class Player : public QObject
{
    Q_OBJECT

    enum Keys {
        C,D,E,F,G,A,B
    };

    QMediaPlayer* media;
    QAudioOutput* output;

    QVector<QMediaPlayer*> mediaPlayerWhite;
    QVector<QAudioOutput*> audioOutputWhite;

    QVector<QMediaPlayer*> mediaPlayerBlack;
    QVector<QAudioOutput*> audioOutputBlack;
public:
    Player();
    ~Player();

    Q_INVOKABLE void whitePressed(int key);
    Q_INVOKABLE void blackPressed(int key);
};

#endif // PLAYER_H
