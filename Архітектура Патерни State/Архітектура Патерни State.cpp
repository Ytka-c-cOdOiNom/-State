#include <iostream>
#include <windows.h>
using namespace std;

// Абстракція для станів лампочки
class State {
public:
    virtual void pressButton() = 0;  // Дія при натисканні кнопки
    virtual ~State() = default;
};

// Контекст (Лампочка)
class Lamp {
private:
    State* currentState;  // Поточний стан лампочки

public:
    Lamp(State* initialState) : currentState(initialState) {}

    // Зміна поточного стану
    void setState(State* newState) {
        currentState = newState;
    }

    // Натискання кнопки для зміни стану
    void pressButton() {
        currentState->pressButton();
    }
};

// Конкретний стан "Вимкнена"
class OffState : public State {
public:
    void pressButton() override {
        cout << "Лампочка увімкнена." << endl;
    }
};

// Конкретний стан "Увімкнена"
class OnState : public State {
public:
    void pressButton() override {
        cout << "Лампочка вимкнена." << endl;
    }
};

// Конкретний стан "Не працює"
class BrokenState : public State {
public:
    void pressButton() override {
        cout << "Лампочка не працює, не можна увімкнути." << endl;
    }
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Створення лампочки в вимкненому стані
    OffState* off = new OffState();
    Lamp lamp(off);

    // Натискаємо кнопку — лампочка увімкнеться
    lamp.pressButton();

    // Тепер лампочка в увімкненому стані
    OnState* on = new OnState();
    lamp.setState(on);

    // Натискаємо кнопку — лампочка вимкнеться
    lamp.pressButton();

    // Тепер лампочка в поламаному стані
    BrokenState* broken = new BrokenState();
    lamp.setState(broken);

    // Натискаємо кнопку — лампочка не працює
    lamp.pressButton();

    delete off;
    delete on;
    delete broken;

    return 0;
}
