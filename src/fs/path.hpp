#ifndef FS__PATH__HPP__
#define FS__PATH__HPP__

#include <string>

namespace fs {

class path {
public:
    u16string const& get_string() const { return str_; }
    
private:
    std::u16string str_;
};

}; // namespace fs

#endif // FS__PATH__HPP__
