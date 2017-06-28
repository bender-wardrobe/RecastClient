/**
 * @file Parcel.hpp
 * @brief Serialization Parcel class header file
 * @author LionZXY
 * @project Recast-client
 * @email nikita@kulikof.ru
 * @date 08.06.17
 *
 * Serialization
 *
 **/

#ifndef RECAST_SERIALIZABLE_HPP
#define RECAST_SERIALIZABLE_HPP


#include <vector>
#include <string>

/**
 * @class Parcel
 *
 * Позволяет переводить удобно данные в массив.
 */
class Parcel {
public:
    Parcel(int code);
    Parcel(std::vector<char> * data);
    ~Parcel();
    Parcel(Parcel &other) = delete;

    int getCode();
    void putString(std::string var);
    template <class T> void put(T var);

    int readInt();
    std::string readString();
    float readFloat();
private:
    int code;
    int curPos;
    std::vector<char> * data;
};


enum ParcelableIDs{
    USER_PARCE = 0,
    UNKNOWN = 0
};

class ISerializable {
public:
    void write(Parcel in);
    void read(Parcel out);
};

#endif //RECAST_SERIALIZABLE_HPP
