#pragma once
#include <string>
#include "Utils.h"

// ENCAPSULATION: data is private, accessed only via public methods.
class Book {
private:
    int id;
    std::string title;
    std::string author;
    bool issued;

public:
    Book(int id, std::string title, std::string author, bool issued = false)
        : id(id), title(std::move(title)), author(std::move(author)), issued(issued) {}

    int getId() const { return id; }
    const std::string& getTitle() const { return title; }
    const std::string& getAuthor() const { return author; }
    bool isIssued() const { return issued; }

    void issue() { issued = true; }
    void giveBack() { issued = false; }

    // For file persistence: id|title|author|issued
    std::string serialize() const {
        return std::to_string(id) + "|" + title + "|" + author + "|" + (issued ? "1" : "0");
    }

    static Book deserialize(const std::string& line) {
        auto p = split(line, '|');
        return Book(std::stoi(p.at(0)), p.at(1), p.at(2), p.at(3) == "1");
    }
};
