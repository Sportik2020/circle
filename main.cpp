#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(800, 600), "SFML Works!");
    //window.setVerticalSyncEnabled(true);
    //или
    window.setFramerateLimit(120);
    //Создаем игровые обьекты
    const float radius = 50.f;
    CircleShape circle(radius);
    CircleShape circle2(radius);
    float dx = 1.f;
    float dy = 1.f;
    circle.move(0, 600 / 2 - radius);
    circle2.move(800 / 2 - radius, 0);
    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }
        //Обновление игры
        circle.move(dx, 0);
        if (circle.getPosition().x + 2 * radius >= 800 || circle.getPosition().x <= 0) {
            dx = -dx;
        }
        circle2.move(0, dy);
        if (circle2.getPosition().y + 2 * radius >= 600 || circle2.getPosition().y <= 0) {
            dy = -dy;
        }
        // Отрисовка обьектов или окна
        window.clear();
        window.draw(circle);
        window.draw(circle2);
        window.display();
    }

    return 0;
}