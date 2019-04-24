/* 
 * File:   govie.h
 * Author: hdamron1594
 *
 * Created on August 29, 2016, 10:21 AM
 */

#ifndef GOVIE_H
#define GOVIE_H

#include <string>

class govie {
public:
    govie();
    govie(std::string);
    virtual ~govie();
    void scream() const;
    void set_name(std::string);
    std::string get_name() const;
    void disp_welcome() const;
private:
    std::string name;
};

#endif /* GOVIE_H */

