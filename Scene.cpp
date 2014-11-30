#include <GL/glu.h>
#include <QDir>
#include "ObjLoader.h"
#include "Scene.h"

Scene::Scene( QWidget *parent ) :
    QGLWidget( parent ),
    m_objId( 0 ),
    m_angle( 0 )
{
    connect( &m_timer, SIGNAL( timeout( ) ),
             this, SLOT( slotUpdate( ) ) );
    m_timer.start( 50 );
}

void Scene::slotUpdate( )
{
    ++m_angle;
    if ( m_angle >= 360 )
    {
        m_angle = 0;
    }
    updateGL( );
}

void Scene::slotSetObject( const QString &fileName )
{
    m_objId = ObjLoader::loadObject( fileName.toStdString( ).c_str( ) );
}

void Scene::initializeGL( )
{
    glClearColor( 0.5f, 0.5f, 0.5f, 1.0f );
    glEnable( GL_DEPTH_TEST );

    glEnable( GL_LIGHTING ); // we enable lighting, to make the 3D object to 3D
    glEnable( GL_LIGHT0 );
    float col[] = { 1.0, 1.0, 1.0, 1.0 }; //light color is white
    glLightfv( GL_LIGHT0, GL_DIFFUSE, col );

    // Remove comment for to enable fog
//    glEnable( GL_FOG ); // we enable fog
//    glFogi( GL_FOG_MODE, GL_LINEAR );
//    glFogf( GL_FOG_START, 1.0 );
//    glFogf( GL_FOG_END, 5.0 );
//    float fogColor[] = { 0.5, 0.5, 0.5, 1.0 };
//    glFogfv( GL_FOG_COLOR, fogColor );
}

void Scene::paintGL( )
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity( );
    float pos[] = { 0.0, 0.0, 5.0, 1.0 }; //set the position
    glLightfv( GL_LIGHT0, GL_POSITION, pos );
    glTranslatef( 0.0, 0.0, -5.0 );
    glRotatef( m_angle, 1.0, 1.0, 1.0 );
    if ( m_objId != 0 ) {
        glCallList( m_objId ); //draw the 3D mesh
    }
}

void Scene::resizeGL( int w, int h )
{
    // Prevent a divide by zero
    if ( h == 0 )
        h = 1;

    // Set Viewport to window dimensions
    glViewport( 0, 0, w, h );

    // Reset coordinate system
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    // Produce the perspective projection
    gluPerspective( 45, 640.0 / 480.0, 1.0, 500.0 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
}
