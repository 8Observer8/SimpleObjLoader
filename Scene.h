#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <QTimer>

class Scene : public QGLWidget
{
    Q_OBJECT
public:
    Scene( QWidget *parent = 0 );

public slots:
    void slotSetObject( const QString &fileName );

private slots:
    void slotUpdate( );

private:
    void initializeGL( );
    void paintGL( );
    void resizeGL( int w, int h );

private:
    int m_objId;
    int m_angle;
    QTimer m_timer;
};

#endif // SCENE_H
