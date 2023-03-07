#pragma once

#include <memory>

enum op_type_   { unknwn_ = -1, ptr_plus_, var_plus_, ptr_minus_, var_minus_, assign_, not_equal_ };
enum expr_type_ { int_lit_expr_, bin_op_expr_, ptr_expr_ };

struct expression_ {
    expr_type_ expression_type;
};

struct integer_literal_ : expression_ {
    int intlit {};

    integer_literal_(const int u_intlit = 0)
        :
        intlit {u_intlit}
    {
        expression_type = int_lit_expr_;
    }
};

struct pointer_ : expression_ {
    char** ptr;

    pointer_(char** u_ptr = nullptr)
        :
        ptr {u_ptr}
    {
        expression_type = ptr_expr_;
    }
};

struct binary_operation_ : expression_ {
    std::shared_ptr <expression_> left;
    std::shared_ptr <expression_> right;
    op_type_ operation;

    binary_operation_(std::shared_ptr <expression_> u_left, 
            op_type_ u_operation, std::shared_ptr <expression_> u_right)
        :
        left {std::move(u_left)},
        operation {u_operation},
        right {std::move(u_right)}
    {
        expression_type = bin_op_expr_;
    }
};
