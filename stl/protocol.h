//
// Created by bencong on 2017/11/7.
//

#include <string>

#ifndef CPLUS_PROTOCOL_H
#define CPLUS_PROTOCOL_H

#endif //CPLUS_PROTOCOL_H

struct VD {
    uint32_t view_;
    std::string digest_;

    bool operator==(const VD& rhs) {
        return view_ == rhs.view_
               && digest_ == rhs.digest_;
    }
};

template <class T> inline void hash_combine(std::size_t & seed, const T & v) {
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std {
    template<> struct hash<VD> {
        typedef VD argument_type;
        typedef size_t result_type;
        result_type operator()(argument_type const& s) const noexcept
        {
            std::size_t seed = 0;
            hash_combine(seed, s.view_);
            hash_combine(seed, s.digest_);
            return seed;
        }
    };
}



class Protocol {
    VD vd;
};