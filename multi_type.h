//
// Created by Jan_M720 on 18.09.2017.
//

#ifndef MULTI_TYPE_MULTI_TYPE_H
#define MULTI_TYPE_MULTI_TYPE_H

template<typename head, typename...tail> struct multi_type : public multi_type<tail...>
{
private:
    head m_val;

protected:

public:

    multi_type() = default;

    multi_type(head&& val, tail&&... rem) : m_val(std::forward<head>(val)), multi_type<tail...>(std::forward<tail>(rem)...){}
    multi_type(const head& val, const tail&... rem) : m_val(val), multi_type<tail...>(rem...){}


    using multi_type<tail...>::operator=;
    multi_type& operator=(const head& value) {m_val = value;}
    multi_type& operator=(head&& value) {m_val = value;}

    operator head& () { return m_val;}

};

template<typename head> struct multi_type<head>
{
private:
    head m_val;
public:

    multi_type() = default;

    multi_type(head&& val) : m_val(std::forward<head>(val)){}
    multi_type(const head& val) : m_val(val){}



    multi_type& operator=(const head& value) {m_val = value;}
    multi_type& operator=(head&& value) {m_val = value;}

    operator head& () { return m_val;}
};

#endif //MULTI_TYPE_MULTI_TYPE_H
