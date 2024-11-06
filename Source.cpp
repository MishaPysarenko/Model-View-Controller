#include <string>
#include <iostream>

class Model {
private:
    std::string data;
public:
    Model() : data("Initial data") {}

    void setData(const std::string& newData) {
        data = newData;
    }

    std::string getData() const {
        return data;
    }
};

class View {
public:
    void displayData(const std::string& data) {
        std::cout << "Displaying Data: " << data << std::endl;
    }
};

class Controller {
private:
    Model& model;
    View& view;

public:
    Controller(Model& m, View& v) : model(m), view(v) {}

    void setData(const std::string& newData) {
        model.setData(newData);
    }

    void updateView() {
        view.displayData(model.getData());
    }
};

int main() {
    Model model;
    View view;
    Controller controller(model, view);

    // Изменение данных через контроллер
    controller.setData("Updated data");

    // Обновление представления
    controller.updateView();

    return 0;
}
