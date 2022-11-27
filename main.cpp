#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    // ������, �������, ����������, �������� ������� ����� ����������
    RenderWindow window(VideoMode(800, 600), "SFML Works!");
    //window.setVerticalSyncEnabled(true);
    //���
    window.setFramerateLimit(120);
    //������� ������� �������
    const float radius = 50.f;
    CircleShape circle(radius);
    CircleShape circle2(radius);
    float dx = 1.f;
    float dy = 1.f;
    circle.move(0, 600 / 2 - radius);
    circle2.move(800 / 2 - radius, 0);
    // ������� ���� ����������. �����������, ���� ������� ����
    while (window.isOpen())
    {
        // ������������ ������� ������� � �����
        Event event;
        while (window.pollEvent(event))
        {
            // ������������ ����� �� �������� � ����� ������� ����?
            if (event.type == Event::Closed)
                // ����� ��������� ���
                window.close();
        }
        //���������� ����
        circle.move(dx, 0);
        if (circle.getPosition().x + 2 * radius >= 800 || circle.getPosition().x <= 0) {
            dx = -dx;
        }
        circle2.move(0, dy);
        if (circle2.getPosition().y + 2 * radius >= 600 || circle2.getPosition().y <= 0) {
            dy = -dy;
        }
        // ��������� �������� ��� ����
        window.clear();
        window.draw(circle);
        window.draw(circle2);
        window.display();
    }

    return 0;
}