// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interface:srv/Drawpoly.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__SRV__DETAIL__DRAWPOLY__STRUCT_HPP_
#define CUSTOM_INTERFACE__SRV__DETAIL__DRAWPOLY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interface__srv__Drawpoly_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_interface__srv__Drawpoly_Request __declspec(deprecated)
#endif

namespace custom_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Drawpoly_Request_
{
  using Type = Drawpoly_Request_<ContainerAllocator>;

  explicit Drawpoly_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0ll;
    }
  }

  explicit Drawpoly_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0ll;
    }
  }

  // field types and members
  using _a_type =
    int64_t;
  _a_type a;

  // setters for named parameter idiom
  Type & set__a(
    const int64_t & _arg)
  {
    this->a = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interface::srv::Drawpoly_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interface::srv::Drawpoly_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interface::srv::Drawpoly_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interface::srv::Drawpoly_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interface::srv::Drawpoly_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interface::srv::Drawpoly_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interface::srv::Drawpoly_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interface::srv::Drawpoly_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interface::srv::Drawpoly_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interface::srv::Drawpoly_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interface__srv__Drawpoly_Request
    std::shared_ptr<custom_interface::srv::Drawpoly_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interface__srv__Drawpoly_Request
    std::shared_ptr<custom_interface::srv::Drawpoly_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Drawpoly_Request_ & other) const
  {
    if (this->a != other.a) {
      return false;
    }
    return true;
  }
  bool operator!=(const Drawpoly_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Drawpoly_Request_

// alias to use template instance with default allocator
using Drawpoly_Request =
  custom_interface::srv::Drawpoly_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interface


#ifndef _WIN32
# define DEPRECATED__custom_interface__srv__Drawpoly_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_interface__srv__Drawpoly_Response __declspec(deprecated)
#endif

namespace custom_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Drawpoly_Response_
{
  using Type = Drawpoly_Response_<ContainerAllocator>;

  explicit Drawpoly_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0ll;
    }
  }

  explicit Drawpoly_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0ll;
    }
  }

  // field types and members
  using _x_type =
    int64_t;
  _x_type x;

  // setters for named parameter idiom
  Type & set__x(
    const int64_t & _arg)
  {
    this->x = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interface::srv::Drawpoly_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interface::srv::Drawpoly_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interface::srv::Drawpoly_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interface::srv::Drawpoly_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interface::srv::Drawpoly_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interface::srv::Drawpoly_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interface::srv::Drawpoly_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interface::srv::Drawpoly_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interface::srv::Drawpoly_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interface::srv::Drawpoly_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interface__srv__Drawpoly_Response
    std::shared_ptr<custom_interface::srv::Drawpoly_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interface__srv__Drawpoly_Response
    std::shared_ptr<custom_interface::srv::Drawpoly_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Drawpoly_Response_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    return true;
  }
  bool operator!=(const Drawpoly_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Drawpoly_Response_

// alias to use template instance with default allocator
using Drawpoly_Response =
  custom_interface::srv::Drawpoly_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interface

namespace custom_interface
{

namespace srv
{

struct Drawpoly
{
  using Request = custom_interface::srv::Drawpoly_Request;
  using Response = custom_interface::srv::Drawpoly_Response;
};

}  // namespace srv

}  // namespace custom_interface

#endif  // CUSTOM_INTERFACE__SRV__DETAIL__DRAWPOLY__STRUCT_HPP_
