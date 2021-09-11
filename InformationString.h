#pragma once

#include <QString>

class InformationString {
    static QString string;

public:
    static void setString(QString str) {
        string = str;
    }

    static QString getString() {
        return string;
    }

};

