#ifndef LINESHAPE_H
#define LINESHAPE_H

#include <Graphics/Export.hpp>
#include <Graphics/Shape.hpp>

namespace sf
{
    class SFML_GRAPHICS_API LineShape : public Shape
    {
    public:
        explicit LineShape(const Vector2f& point1, const Vector2f& point2);
        void setThickness(float thickness);
        float getThickness() const;
        float getLength() const;
        virtual std::size_t getPointCount() const;
        virtual Vector2f getPoint(std::size_t index) const;
    private :
        Vector2f m_direction;
        float m_thickness;

    };
}//namespace sf


#endif // LINESHAPE_H
