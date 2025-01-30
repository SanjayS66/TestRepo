// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interface:srv/Drawpoly.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__SRV__DETAIL__DRAWPOLY__BUILDER_HPP_
#define CUSTOM_INTERFACE__SRV__DETAIL__DRAWPOLY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interface/srv/detail/drawpoly__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interface
{

namespace srv
{

namespace builder
{

class Init_Drawpoly_Request_a
{
public:
  Init_Drawpoly_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interface::srv::Drawpoly_Request a(::custom_interface::srv::Drawpoly_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interface::srv::Drawpoly_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interface::srv::Drawpoly_Request>()
{
  return custom_interface::srv::builder::Init_Drawpoly_Request_a();
}

}  // namespace custom_interface


namespace custom_interface
{

namespace srv
{

namespace builder
{

class Init_Drawpoly_Response_x
{
public:
  Init_Drawpoly_Response_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interface::srv::Drawpoly_Response x(::custom_interface::srv::Drawpoly_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interface::srv::Drawpoly_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interface::srv::Drawpoly_Response>()
{
  return custom_interface::srv::builder::Init_Drawpoly_Response_x();
}

}  // namespace custom_interface

#endif  // CUSTOM_INTERFACE__SRV__DETAIL__DRAWPOLY__BUILDER_HPP_
