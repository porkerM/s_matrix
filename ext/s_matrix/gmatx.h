#ifndef _GMATX_H_
#define _GMATX_H_

#include "matx_title.h"
#include "matx_content.h"
#include "matx_type_def.h"

class GMatx
{
public:
    GMatx(void);

    void add_row(const std::string& id, const t_key_value_hash& row_content);

    // 当找不到id所对应的行时，返回的t_key_value_hash数据的size=0
    // size of t_key_value_hash will be zero when couldn't find the row.
    t_key_value_hash get_row(const std::string& id) const;
    const std::vector<std::string>& get_titles(void) const;
    std::string to_s(void) const;
    size_t size(void) const;

    t_key_value_hash first(std::string& id_out) const;

    // iterator function
    // the args parameter of each_call function will pass to callback function each_call_func.
    // the return of each_call_func indicate continue iterator or not. - true means continue. false means break.
    static bool t_continue;
    static bool t_break;
    typedef bool (*each_call_func)(const std::string& /*id*/, const t_key_value_hash& /*row_content*/, void* args);
    void each_call(each_call_func func, void* args) const;

private:
    MatxTitle m_titles;
    MatxContent m_contents;
};

#endif
