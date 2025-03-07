#include "nonpenetrationmanager.h"

NonPenetrationManager::NonPenetrationManager()
    :mmovables()
{}

// NonPenetrationManager::~NonPenetrationManager()
// {
//     // for(auto& c : movables)
//     // {
//     //     c->eraseManager(this);
//     // }
//     // for(auto& c : stables)
//     // {
//     //     c->eraseManager(this);
//     // }
// }

void NonPenetrationManager::handleContact(Creature& movCrt, const QGraphicsItem& fixObj)
{
    static QTransform st_qtr;

    for (int i=0; i<fixObj.shape().elementCount()-1; i++ )
    {
        static QPainterPath st_qpp;
        st_qpp.clear();
        st_qpp.moveTo(fixObj.shape().elementAt(i));
        st_qpp.lineTo(fixObj.shape().elementAt(i+1));

        // find collision sides of fixObj
        if ( movCrt.collidesWithPath( movCrt.mapFromItem(&fixObj ,st_qpp)) )
        {
            // in fixObj coords
            QPointF p_1 = QPointF(st_qpp.elementAt(0));
            QPointF p_c = fixObj.mapFromItem(&movCrt, movCrt.boundingRect().center());
            QPointF p_2 = QPointF(st_qpp.elementAt(1));

            // TO LINE COORDS
            p_c-=p_1;
            p_2-=p_1;
            qreal alpha = QLineF({0,0},p_2).angle()*3.14159/180;
            st_qtr.reset();
            st_qtr.rotateRadians(alpha);
            QPointF vlin = st_qtr.map(p_c)+QPointF(0,movCrt.contact_radius);

            //QPointF p2lin = st_qtr.map(p_2); // p_2.y() not affect

            // to prevent corner jumps
            if(vlin.x()<movCrt.step || (vlin.x() > (st_qtr.map(p_2).x()-movCrt.step)))
            {
                continue;
            }

            // TO WALL ITEM COORDS
            st_qtr.reset();
            st_qtr.rotateRadians(-alpha);
            QPointF vloc = st_qtr.map(QPointF(0,vlin.y()));

            // TO SCENE COORDS
            st_qtr.reset();
            st_qtr.rotate(fixObj.rotation());
            QPointF vg = st_qtr.map(-vloc);

            // CHECK DEPTH
            if(vlin.y()>(0))
            {
                movCrt.moveBy(vg.x(),vg.y());
            }

        }
    }
}

void NonPenetrationManager::handle()
{
    for(MapEntity* c: mmovables.getElements())
    {
        for(MapEntity* w: mstables.getElements())
        {
            if( w->collidesWithItem( c ) )
            {
                //handleContact( static_cast<Creature>(*c) , *w);     // VISITOR
            }
        }
    }
}

// void NonPenetrationManager::addMovable(Creature* c)
// {
//     //movables.insert(c);
//     //c->insertManager(this);

//     mmovables.add(c);
// }
// void NonPenetrationManager::addStable(MapEntity* e)
// {
//     // stables.insert(e);
//     // e->insertManager(this);

//     mstables.add(e);
// }

// void NonPenetrationManager::erase(MapEntity* el)
// {
//     // auto cit = std::find_if(movables.begin(),movables.end(), [el](auto& r){ return el == r; } );
//     // if(cit != movables.end())
//     // {
//     //     movables.erase(cit);
//     // }

//     // auto sit = std::find_if(stables.begin(),stables.end(), [el](auto& r){ return el == r; } );
//     // if(sit != stables.end())
//     // {
//     //     stables.erase(sit);
//     // }
// }

