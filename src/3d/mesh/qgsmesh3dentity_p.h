/***************************************************************************
                         qgsmesh3dentity.h
                         -------------------------
    begin                : january 2020
    copyright            : (C) 2020 by Vincent Cloarec
    email                : vcloarec at gmail dot com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSMESHENTITY_H
#define QGSMESHENTITY_H

#include <Qt3DCore/QEntity>

#include "mesh/qgsmesh3dgeometry_p.h"
#include "qgs3dmapsettings.h"
#include "qgsmesh3dsymbol.h"
#include "qgsterraintileentity_p.h"

///@cond PRIVATE

//
//  W A R N I N G
//  -------------
//
// This file is not part of the QGIS API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//

class Qgs3DMapSettings;
class QgsTessellatedPolygonGeometry;
class QgsMesh3DSymbol;

class QgsMeshLayer;
class QgsMesh3dMaterial;

//! Entity that handles rendering of mesh
class QgsMesh3dEntity: public Qt3DCore::QEntity
{
  public:
    //! Constructor
    QgsMesh3dEntity( const Qgs3DMapSettings &map,
                     const QgsTriangularMesh triangularMesh,
                     const QgsRectangle &extent,
                     const QgsMesh3DSymbol &symbol );

    //! Builds the geometry and the material
    void build();

  private:
    virtual void buildGeometry();
    virtual void applyMaterial();

    QgsRectangle mExtent;
    QgsMesh3DSymbol mSymbol;
    Qgs3DMapSettings mMapSettings;
    QgsTriangularMesh mTriangularMesh;
    QgsMesh3dMaterial *mMaterial = nullptr;

    static int mMesh3DEntityCount;
    QString name;
};

//! Entity that handles rendering of terrain mesh
class QgsMesh3dTerrainTileEntity: public QgsTerrainTileEntity
{
  public:
    QgsMesh3dTerrainTileEntity( const Qgs3DMapSettings &map,
                                const QgsTriangularMesh triangularMesh,
                                const QgsRectangle &extent,
                                const QgsMesh3DSymbol &symbol,
                                QgsChunkNodeId nodeId,
                                Qt3DCore::QNode *parent = nullptr );

    void build();

  private:
    virtual void buildGeometry();
    virtual void applyMaterial();

    QgsRectangle mExtent;
    QgsMesh3DSymbol mSymbol;
    Qgs3DMapSettings mMapSettings;
    QgsTriangularMesh mTriangularMesh;
    QgsMesh3dMaterial *mMaterial = nullptr;

    static int mMesh3DEntityCount;
    QString name;
};

///@endcond

#endif // QGSMESHENTITY_H
