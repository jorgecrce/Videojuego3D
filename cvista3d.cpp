#include "cvista3d.h"

CVista3D::CVista3D()
{
    comunicacion_cliente = new CComunicacionCliente;
    escena = new CEscena;
    escena3d = new osg::Group();

    //Modelos Baldosas
    Node_BaldosaBlanca = osgDB::readNodeFile( "sii-baldosa.3ds" );
    Node_BaldosaGris   = osgDB::readNodeFile( "sii-baldosa.3ds" );
    Node_BaldosaNegra  = osgDB::readNodeFile( "sii-baldosa.3ds" );

    Node_BaldosaBlanca_SS = Node_BaldosaBlanca->getOrCreateStateSet();
    Node_BaldosaGris_SS   = Node_BaldosaGris  ->getOrCreateStateSet();
    Node_BaldosaNegra_SS  = Node_BaldosaNegra ->getOrCreateStateSet();

    Node_BaldosaBlanca_Material = new osg::Material;
    Node_BaldosaGris_Material   = new osg::Material;
    Node_BaldosaNegra_Material  = new osg::Material;

    Node_BaldosaBlanca_Material->setDiffuse(osg::Material::FRONT,osg::Vec4(1.0f ,1.0f ,1.0f ,1.0f));
    Node_BaldosaGris_Material  ->setDiffuse(osg::Material::FRONT,osg::Vec4(0.75f,0.75f,0.75f,1.0f));
    Node_BaldosaNegra_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f ,0.0f ,0.0f ,1.0f));

    Node_BaldosaBlanca_SS->setAttribute(Node_BaldosaBlanca_Material.get());
    Node_BaldosaGris_SS  ->setAttribute(Node_BaldosaGris_Material  .get());
    Node_BaldosaNegra_SS ->setAttribute(Node_BaldosaNegra_Material .get());

    //Modelos Esferas
    Esfera               = new osg::Sphere(osg::Vec3(0,0,0), 1.0);
    ShapeDrawable_Esfera = new osg::ShapeDrawable(Esfera);

    Geode_EsferaRoja  = new osg::Geode();
    Geode_EsferaVerde = new osg::Geode();
    Geode_EsferaAzul  = new osg::Geode();

    Node_EsferaRoja_SS  = Geode_EsferaRoja ->getOrCreateStateSet();
    Node_EsferaVerde_SS = Geode_EsferaVerde->getOrCreateStateSet();
    Node_EsferaAzul_SS  = Geode_EsferaAzul ->getOrCreateStateSet();

    Node_EsferaRoja_Material  = new osg::Material;
    Node_EsferaVerde_Material = new osg::Material;
    Node_EsferaAzul_Material  = new osg::Material;

    Geode_EsferaRoja ->addDrawable(ShapeDrawable_Esfera);
    Geode_EsferaVerde->addDrawable(ShapeDrawable_Esfera);
    Geode_EsferaAzul ->addDrawable(ShapeDrawable_Esfera);

    Node_EsferaRoja_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(1.0f,0.0f,0.0f,1.0f));
    Node_EsferaVerde_Material->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f,1.0f,0.0f,1.0f));
    Node_EsferaAzul_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f,0.0f,1.0f,1.0f));

    Node_EsferaRoja_SS ->setAttribute(Node_EsferaRoja_Material .get());
    Node_EsferaVerde_SS->setAttribute(Node_EsferaVerde_Material.get());
    Node_EsferaAzul_SS ->setAttribute(Node_EsferaAzul_Material .get());

    //Modelo Caja
    Node_CajaRoja  = osgDB::readNodeFile( "chest.stl" );
    Node_CajaVerde = osgDB::readNodeFile( "chest.stl" );
    Node_CajaAzul  = osgDB::readNodeFile( "chest.stl" );

    Node_CajaRoja_SS  = Node_CajaRoja ->getOrCreateStateSet();
    Node_CajaVerde_SS = Node_CajaVerde->getOrCreateStateSet();
    Node_CajaAzul_SS  = Node_CajaAzul ->getOrCreateStateSet();

    Node_CajaRoja_Material  = new osg::Material;
    Node_CajaVerde_Material = new osg::Material;
    Node_CajaAzul_Material  = new osg::Material;

    Node_CajaRoja_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(1.0f,0.0f,0.0f,1.0f));
    Node_CajaVerde_Material->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f,1.0f,0.0f,1.0f));
    Node_CajaAzul_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f,0.0f,1.0f,1.0f));

    Node_CajaRoja_SS ->setAttribute(Node_CajaRoja_Material .get());
    Node_CajaVerde_SS->setAttribute(Node_CajaVerde_Material.get());
    Node_CajaAzul_SS ->setAttribute(Node_CajaAzul_Material .get());

    //Modelo Persona Forma
    Node_PersonaFormaRoja  = osgDB::readNodeFile( "sii-persona.stl" );
    Node_PersonaFormaVerde = osgDB::readNodeFile( "sii-persona.stl" );
    Node_PersonaFormaAzul  = osgDB::readNodeFile( "sii-persona.stl" );

    Node_PersonaFormaRoja_SS  = Node_PersonaFormaRoja ->getOrCreateStateSet();
    Node_PersonaFormaVerde_SS = Node_PersonaFormaVerde->getOrCreateStateSet();
    Node_PersonaFormaAzul_SS  = Node_PersonaFormaAzul ->getOrCreateStateSet();

    Node_PersonaFormaRoja_Material  = new osg::Material;
    Node_PersonaFormaVerde_Material = new osg::Material;
    Node_PersonaFormaAzul_Material  = new osg::Material;

    Node_PersonaFormaRoja_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(1.0f,0.0f,0.0f,1.0f));
    Node_PersonaFormaVerde_Material->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f,1.0f,0.0f,1.0f));
    Node_PersonaFormaAzul_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f,0.0f,1.0f,1.0f));

    Node_PersonaFormaRoja_SS ->setAttribute(Node_PersonaFormaRoja_Material .get());
    Node_PersonaFormaVerde_SS->setAttribute(Node_PersonaFormaVerde_Material.get());
    Node_PersonaFormaAzul_SS ->setAttribute(Node_PersonaFormaAzul_Material .get());

    //Modelo Robot
    Node_RobotRojo  = osgDB::readNodeFile( "walle.stl" );
    Node_RobotVerde = osgDB::readNodeFile( "walle.stl" );
    Node_RobotAzul  = osgDB::readNodeFile( "walle.stl" );

    Node_RobotRojo_SS  = Node_RobotRojo ->getOrCreateStateSet();
    Node_RobotVerde_SS = Node_RobotVerde->getOrCreateStateSet();
    Node_RobotAzul_SS  = Node_RobotAzul ->getOrCreateStateSet();

    Node_RobotRojo_Material  = new osg::Material;
    Node_RobotVerde_Material = new osg::Material;
    Node_RobotAzul_Material  = new osg::Material;

    Node_RobotRojo_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(1.0f ,0.0f ,0.0f ,1.0f));
    Node_RobotVerde_Material->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f ,1.0f ,0.0f ,1.0f));
    Node_RobotAzul_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f ,0.0f ,1.0f ,1.0f));

    Node_RobotRojo_SS ->setAttribute(Node_RobotRojo_Material .get());
    Node_RobotVerde_SS->setAttribute(Node_RobotVerde_Material.get());
    Node_RobotAzul_SS ->setAttribute(Node_RobotAzul_Material .get());

    //Objetos Baldosas
    for(int i = NumBaldosasXMin; i <= NumBaldosasXMax; i++)
    {
        for(int j = NumBaldosasYMin; j <= NumBaldosasYMax; j++)
        {
        osg::ref_ptr<osg::PositionAttitudeTransform> trasformacion = new osg::PositionAttitudeTransform();
        osg::Vec3 posicion(i*0.5,j*0.5,0);
        trasformacion->setPosition(posicion);
        if((i==-100) && (j==-100))
            trasformacion->addChild(Node_BaldosaGris);
        else
            if((i+j)%2)
                trasformacion->addChild(Node_BaldosaNegra);
            else
                trasformacion->addChild(Node_BaldosaBlanca);
        escena3d->addChild(trasformacion);
        }
    }


    //Vista
    vista.setSceneData( escena3d );
    vista.setCameraManipulator(new osgGA::TrackballManipulator);
    vista.setUpViewInWindow(0, 0, 500, 500);
    vista.realize();
}

CVista3D::~CVista3D()
{
    if(escena)
        escena->DesconectarVista3D(this);

    delete comunicacion_cliente;
}

void CVista3D::Escena(CEscena* _escena)
{
    if(escena)
        escena->DesconectarVista3D(this);

    esferas3d .clear();
    cajas3d   .clear();
    personas3d.clear();
    robots3d  .clear();

    nodos_esferas .clear();
    nodos_cajas   .clear();
    nodos_personas.clear();
    nodos_robots  .clear();

    escena=_escena;

    for(unsigned int esfera = 0; esfera < escena->NumEsferas(); esfera++)
        NuevaEsfera(escena->Esfera(esfera)->Color(), escena->Esfera(esfera)->Posicion());

    for(unsigned int caja = 0; caja < escena->NumCajas(); caja++)
        NuevaCaja(escena->Caja(caja)->Color(), escena->Caja(caja)->Posicion());

    for(unsigned int persona = 0; persona < escena->NumPersonas(); persona++)
        NuevaPersona(escena->Persona(persona)->Color(), escena->Persona(persona)->Posicion(), escena->Persona(persona)->Orientacion());

    for(unsigned int robot = 0; robot < escena->NumRobots(); robot++)
        NuevoRobot(escena->Robot(robot)->Color(), escena->Robot(robot)->Posicion(), escena->Robot(robot)->Orientacion());

    escena->ConectarVista3D(this);
}

CEscena* CVista3D::Escena(void)
{
    return escena;
}

void CVista3D::NuevaEsfera(TColor color, TPosicion posicion)
{
    CEsfera3D* esfera3d = new CEsfera3D;

    esfera3d->id    = escena->NumEsferas();
    esfera3d->radio = ESFERA_RADIO*2;
    esfera3d->x     = posicion.x;
    esfera3d->y     = posicion.y;
    esfera3d->z     = AlturaBaldosa + esfera3d->radio;
    esfera3d->color = color;
    esferas3d.push_back(*esfera3d);

    osg::ref_ptr<osg::PositionAttitudeTransform> trasformacion = new osg::PositionAttitudeTransform();
    nodos_esferas.push_back(trasformacion);
    osg::Vec3 position(esfera3d->x, -esfera3d->y, esfera3d->z);
    trasformacion->setPosition(position);
    trasformacion->setScale(osg::Vec3(esfera3d->radio, esfera3d->radio, esfera3d->radio));

    switch(color)
    {
    case Rojo:
        trasformacion->addChild(Geode_EsferaRoja);
        break;
    case Verde:
        trasformacion->addChild(Geode_EsferaVerde);
        break;
    case Azul:
        trasformacion->addChild(Geode_EsferaAzul);
        break;
    }

    escena3d->addChild(trasformacion);
}

void CVista3D::NuevaCaja(TColor color, TPosicion posicion)
{
    float height;
    CCaja3D* caja3d = new CCaja3D;

    caja3d->id     = escena->NumCajas();
    caja3d->radio  = CAJA_RADIO;
    caja3d->altura = CAJA_ALTURA;
    caja3d->x      = posicion.x;
    caja3d->y      = posicion.y;
    caja3d->z      = AlturaBaldosa;
    caja3d->color  = color;
    cajas3d.push_back(*caja3d);

    osg::ref_ptr<osg::PositionAttitudeTransform> trasformacion = new osg::PositionAttitudeTransform();
    nodos_cajas.push_back(trasformacion);
    osg::Vec3 position(caja3d->x, -caja3d->y, caja3d->z);
    trasformacion->setPosition(position);
    height=Node_CajaRoja->getBound().radius();
    trasformacion->setScale(osg::Vec3(CAJA_ALTURA/height,CAJA_ALTURA/height,CAJA_ALTURA/height));

    switch(color)
    {
        case Rojo:
            trasformacion->addChild(Node_CajaRoja);
            break;
        case Verde:
            trasformacion->addChild(Node_CajaVerde);
            break;
        case Azul:
            trasformacion->addChild(Node_CajaAzul);
            break;
    }

    escena3d->addChild(trasformacion);
}

void CVista3D::NuevaPersona(TColor color, TPosicion posicion, float orientacion)
{
    float height;
    CPersona3D* persona3d = new CPersona3D;

    persona3d->id     = escena->NumPersonas();
    persona3d->radio  = PERSONA_RADIO;
    persona3d->altura = PERSONA_ALTURA;
    persona3d->x      = posicion.x;
    persona3d->y      = posicion.y;
    persona3d->z      = AlturaBaldosa + persona3d->altura/2;
    persona3d->color  = color;
    personas3d.push_back(*persona3d);

    osg::ref_ptr<osg::PositionAttitudeTransform> trasformacion = new osg::PositionAttitudeTransform();
    nodos_personas.push_back(trasformacion);
    osg::Vec3 position(persona3d->x, -persona3d->y, persona3d->z);
    trasformacion->setPosition(position);
    height=2*(Node_PersonaFormaRoja->getBound().radius());
    trasformacion->setScale(osg::Vec3(PERSONA_ALTURA/height,PERSONA_ALTURA/height,PERSONA_ALTURA/height));
    trasformacion->setAttitude(osg::Quat(orientacion+osg::DegreesToRadians(90.0), osg::Vec3(0,0,1)));

    switch(color)
    {
        case Rojo:
            trasformacion->addChild(Node_PersonaFormaRoja);
            break;
        case Verde:
            trasformacion->addChild(Node_PersonaFormaVerde);
            break;
        case Azul:
            trasformacion->addChild(Node_PersonaFormaAzul);
            break;
    }

    escena3d->addChild(trasformacion);
}

void CVista3D::NuevoRobot(TColor color, TPosicion posicion, float orientacion)
{
    float height;
    CRobot3D* robot3d = new CRobot3D;

    robot3d->id     = escena->NumRobots();
    robot3d->radio  = ROBOT_RADIO;
    robot3d->altura = ROBOT_ALTURA;
    robot3d->x      = posicion.x;
    robot3d->y      = posicion.y;
    robot3d->z      = RobotZ;
    robot3d->color  = color;
    robots3d.push_back(*robot3d);

    osg::ref_ptr<osg::PositionAttitudeTransform> trasformacion = new osg::PositionAttitudeTransform();
    nodos_robots.push_back(trasformacion);
    osg::Vec3 position(robot3d->x, -robot3d->y, robot3d->z);
    trasformacion->setPosition(position);
    height=Node_RobotRojo->getBound().radius();
    trasformacion->setScale(osg::Vec3(ROBOT_ALTURA/height,ROBOT_ALTURA/height,ROBOT_ALTURA/height));
    trasformacion->setAttitude(osg::Quat(orientacion-osg::DegreesToRadians(90.0), osg::Vec3(0,0,1)));

    switch(color)
    {
        case Rojo:
            trasformacion->addChild(Node_RobotRojo);
            break;
        case Verde:
            trasformacion->addChild(Node_RobotVerde);
            break;
        case Azul:
            trasformacion->addChild(Node_RobotAzul);
            break;
    }

    escena3d->addChild(trasformacion);
}

void CVista3D::PosicionEsfera(unsigned int esfera, TPosicion posicion)
{
    osg::Vec3 position(posicion.x, -posicion.y, AlturaBaldosa + ESFERA_RADIO);
    nodos_esferas[esfera]->setPosition(position);
}

void CVista3D::PosicionCaja(unsigned int caja, TPosicion posicion)
{
    osg::Vec3 position(posicion.x, -posicion.y, AlturaBaldosa);
    nodos_cajas[caja]->setPosition(position);
}

void CVista3D::PosicionPersona(unsigned int persona, TPosicion posicion)
{
    osg::Vec3 position(posicion.x, -posicion.y, AlturaBaldosa + PERSONA_ALTURA / 2);
    nodos_personas[persona]->setPosition(position);
}

void CVista3D::PosicionRobot(unsigned int robot, TPosicion posicion)
{
    osg::Vec3 position(posicion.x, -posicion.y, RobotZ);
    nodos_robots[robot]->setPosition(position);
}

void CVista3D::OrientacionPersona(unsigned int persona, float orientacion)
{
    osg::Quat orientation(orientacion+osg::DegreesToRadians(90.0), osg::Vec3(0,0,1));
    nodos_personas[persona]->setAttitude(orientation);
}

void CVista3D::OrientacionRobot(unsigned int robot, float orientacion)
{
    osg::Quat orientation(orientacion-osg::DegreesToRadians(90.0), osg::Vec3(0,0,1));
    nodos_robots[robot]->setAttitude(orientation);
}

void CVista3D::BorrarEsferas(void)
{
    for(unsigned int esfera = 0; esfera < escena->NumEsferas(); esfera++)
       escena3d->removeChild(nodos_esferas[esfera]);

    nodos_esferas.clear();
}

void CVista3D::BorrarCajas(void)
{
    for(unsigned int caja = 0; caja < escena->NumCajas(); caja++)
       escena3d->removeChild(nodos_cajas[caja]);

    nodos_cajas.clear();
}

void CVista3D::BorrarPersonas(void)
{
    for(unsigned int persona = 0; persona < escena->NumPersonas(); persona++)
       escena3d->removeChild(nodos_personas[persona]);

    nodos_personas.clear();
}

void CVista3D::BorrarRobots(void)
{
    for(unsigned int robot = 0; robot < escena->NumRobots(); robot++)
       escena3d->removeChild(nodos_robots[robot]);

    nodos_robots.clear();
}

void CVista3D::Actualizar(void)
{
    for(unsigned int esfera = 0; esfera < escena->NumEsferas(); esfera++)
        PosicionEsfera(esfera, escena->Esfera(esfera)->Posicion());

    for(unsigned int caja = 0; caja < escena->NumCajas(); caja++)
        PosicionCaja(caja, escena->Caja(caja)->Posicion());

    for(unsigned int persona = 0; persona < escena->NumPersonas(); persona++)
    {
        PosicionPersona(persona, escena->Persona(persona)->Posicion());
        OrientacionPersona(persona, escena->Persona(persona)->Orientacion());
    }

    for(unsigned int robot = 0; robot < escena->NumRobots(); robot++)
    {
        PosicionRobot(robot, escena->Robot(robot)->Posicion());
        OrientacionRobot(robot, escena->Robot(robot)->Orientacion());
    }
}

void CVista3D::Mostrar(void)
{
    vista.frame();
}

void CVista3D::Guardar(FILE* archivo)
{

}

void CVista3D::Recuperar(FILE *archivo)
{

}
