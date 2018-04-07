/*
 *   AviTab - Aviator's Virtual Tablet
 *   Copyright (C) 2018 Folke Will <folko@solhost.org>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU Affero General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Affero General Public License for more details.
 *
 *   You should have received a copy of the GNU Affero General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef SRC_LIBXDATA_LOADERS_PARSERS_BASEPARSER_H_
#define SRC_LIBXDATA_LOADERS_PARSERS_BASEPARSER_H_

#include <fstream>
#include <string>
#include <functional>
#include <sstream>
#include <iosfwd>

namespace xdata {

class BaseParser {
public:
    using LineFunctor = std::function<void()>;
    BaseParser(const std::string &file);

    std::string parseHeader();
    void eachLine(LineFunctor f);

    bool isEOL();
    std::string restOfLine();
    std::string parseWord();
    int parseInt();
    double parseDouble();
    void skip(char c);

    void skipWhiteSpace();
private:
    std::ifstream stream;
    std::istringstream lineStream;
    std::istream &getLine(std::string &str);
};

} /* namespace xdata */

#endif /* SRC_LIBXDATA_LOADERS_PARSERS_BASEPARSER_H_ */
