////////////////////////////////////////////////////////////
///
/// Zoom C++ library
/// Copyright (C) 2011-2012 ZinLibs (zinlibs@gmail.com)
///
/// This software is provided 'as-is', without any express or implied warranty.
/// In no event will the authors be held liable for any damages arising from the use of this software.
/// Permission is granted to anyone to use this software for any purpose,
/// including commercial applications, and to alter it and redistribute it freely,
/// subject to the following restrictions:
///
/// 1. The origin of this software must not be misrepresented;
///    you must not claim that you wrote the original software.
///    If you use this software in a product, an acknowledgment
///    in the product documentation would be appreciated but is not required.
///
/// 2. Altered source versions must be plainly marked as such,
///    and must not be misrepresented as being the original software.
///
/// 3. This notice may not be removed or altered from any source distribution.
///
////////////////////////////////////////////////////////////

#ifndef ZOOM_SHAPE_HPP
#define ZOOM_SHAPE_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <vector>
#include <SFML/Graphics.hpp>
#include <Zoost/Geom.hpp>
#include <Zoost/Curve.hpp>
#include <Zoom/Color.hpp>
#include <Zoom/Config.hpp>

namespace zin
{
	
class ZOOM_API Shape : public sf::Drawable, public sf::NonCopyable, public Geom::Observer  
{
public:

    ////////////////////////////////////////////////////////////
    // VertexInfo structure
    ////////////////////////////////////////////////////////////
    struct VertexInfo
    {
        bool   showed;
        Color  color;
        Uint16 size;
    };

    ////////////////////////////////////////////////////////////
    // LiaisonInfo structure
    ////////////////////////////////////////////////////////////
    struct LiaisonInfo
    {
        bool   showed;
        Color  color;
        Uint16 width;
    };

    ////////////////////////////////////////////////////////////
    // FaceInfo structure
    ////////////////////////////////////////////////////////////
    struct FaceInfo
    {
        bool  showed;
        bool  enableColor;
        Color color;
    };
    
    ////////////////////////////////////////////////////////////
    // Default constructor
    ////////////////////////////////////////////////////////////
	Shape(Geom& geom);

    ////////////////////////////////////////////////////////////
    // Get the geometry of the shape
    ////////////////////////////////////////////////////////////
    Geom& getGeom();

    ////////////////////////////////////////////////////////////
    // Set the default vertex color
    ////////////////////////////////////////////////////////////
    void setVerticesColor(const Color& color);
    
    ////////////////////////////////////////////////////////////
    // Set the color of the vertex specified by its indice
    ////////////////////////////////////////////////////////////
	void setVertexColor(size_t indice, const Color& color);

    ////////////////////////////////////////////////////////////
    // Set the default liaison color
    ////////////////////////////////////////////////////////////
    void setLiaisonsColor(const Color& color);

    ////////////////////////////////////////////////////////////
    // Set the color of the liaison specified by its indice
    ////////////////////////////////////////////////////////////
    void setLiaisonColor(size_t indice, const Color& color);

    ////////////////////////////////////////////////////////////
    //Set the default face color
    ////////////////////////////////////////////////////////////
    void setFacesColor(const Color& color);

    ////////////////////////////////////////////////////////////
    // Set the color of the face specified by its indice
    ////////////////////////////////////////////////////////////
    void setFaceColor(size_t indice, const Color& color);

    ////////////////////////////////////////////////////////////
    // Set the default vertex size
    ////////////////////////////////////////////////////////////
    void setVerticesSize(Uint16 size);

    ////////////////////////////////////////////////////////////
    // Set the size of the vertex specified by its indice
    ////////////////////////////////////////////////////////////
    void setVertexSize(size_t indice, Uint16 size);

    ////////////////////////////////////////////////////////////
    // Set the default liaison width
    ////////////////////////////////////////////////////////////
    void setLiaisonsWidth(Uint16 size);

    ////////////////////////////////////////////////////////////
    // Set the width of the liaison specified by its indice
    ////////////////////////////////////////////////////////////
    void setLiaisonWidth(size_t indice, Uint16 size);

    ////////////////////////////////////////////////////////////
    // Show or hide the vertices
    ////////////////////////////////////////////////////////////
    void showVertices(bool showed = true);

    ////////////////////////////////////////////////////////////
    // Show or hide the vertex specified by its indice
    ////////////////////////////////////////////////////////////
    void showVertex(size_t indice, bool showed = true);

    ////////////////////////////////////////////////////////////
    // Show or hide the liaisons
    ////////////////////////////////////////////////////////////
    void showLiaisons(bool showed = true);

    ////////////////////////////////////////////////////////////
    // Show or hide the liaison specified by its indice
    ////////////////////////////////////////////////////////////
    void showLiaison(size_t indice, bool showed = true);

    ////////////////////////////////////////////////////////////
    // Show or hide the faces
    ////////////////////////////////////////////////////////////
    void showFaces(bool showed = true);

    ////////////////////////////////////////////////////////////
    // Show or hide the face specified by its indice
    ////////////////////////////////////////////////////////////
    void showFace(size_t indice, bool showed = true);

    ////////////////////////////////////////////////////////////
    // Enable the face color
    ////////////////////////////////////////////////////////////
    void enableFacesColor(bool enabled = true);

    ////////////////////////////////////////////////////////////
    // Enable the face color of the face specified by its indice
    ////////////////////////////////////////////////////////////
    void enableFaceColor(size_t indice, bool used = true);
    
    ////////////////////////////////////////////////////////////
    // Set the debug mode
    ////////////////////////////////////////////////////////////
    void setDebugMode(bool enabled);

    ////////////////////////////////////////////////////////////
    // Get the debug mode
    ////////////////////////////////////////////////////////////
    bool getDebugMode();

protected:
    
    ////////////////////////////////////////////////////////////
    // Draw the shape
    ////////////////////////////////////////////////////////////
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    ////////////////////////////////////////////////////////////
    // Update the rendering of the shape
    ////////////////////////////////////////////////////////////
    void update() const;

    ////////////////////////////////////////////////////////////
    // Method called when the tranform is updated
    ////////////////////////////////////////////////////////////
    void onTransformUpdated();

    ////////////////////////////////////////////////////////////
    // Method called when a vertex is added to the geom
    ////////////////////////////////////////////////////////////
    void onVertexAdded();

    ////////////////////////////////////////////////////////////
    // Method called when a liaison is added to the geom
    ////////////////////////////////////////////////////////////
    void onLiaisonAdded();

    ////////////////////////////////////////////////////////////
    // Method called when a face is added to the geom
    ////////////////////////////////////////////////////////////
    void onFaceAdded();

    ////////////////////////////////////////////////////////////
    // Method called when a vertex is removed from the geom
    ////////////////////////////////////////////////////////////
    void onVertexRemoved(size_t indice);

    ////////////////////////////////////////////////////////////
    // Method called when a liaison is removed from the geom
    ////////////////////////////////////////////////////////////
    void onLiaisonRemoved(size_t indice);

    ////////////////////////////////////////////////////////////
    // Method called when a vertex is removed from the geom
    ////////////////////////////////////////////////////////////
    void onFaceRemoved(size_t indice);

    ////////////////////////////////////////////////////////////
    // Method called when the geom is erased
    ////////////////////////////////////////////////////////////
    void onErasing();

private:

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    bool                                 m_debugMode;
    Geom&                                m_geom;
    mutable std::vector<sf::VertexArray> m_vertexArray;
    mutable bool                         m_needUpdate,
                                         m_isVertexShowed,
                                         m_isLiaisonShowed,
                                         m_isFaceShowed,
                                         m_isFaceColorEnabled;
	Color  		   	                     m_defaultVertexColor,
		   			                     m_defaultLiaisonColor,
                                         m_defaultFaceColor;
	Uint16 			                     m_defaultLiaisonWidth,
		   			                     m_defaultVertexSize;
	std::vector<VertexInfo>              m_vertexInfos;
    std::vector<LiaisonInfo>             m_liaisonInfos;
    std::vector<FaceInfo>                m_faceInfos;
};

}

#endif // ZOOM_SHAPE_HPP