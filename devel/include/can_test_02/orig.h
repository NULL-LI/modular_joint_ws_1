// Generated by gencpp from file can_test_02/orig.msg
// DO NOT EDIT!


#ifndef CAN_TEST_02_MESSAGE_ORIG_H
#define CAN_TEST_02_MESSAGE_ORIG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace can_test_02
{
template <class ContainerAllocator>
struct orig_
{
  typedef orig_<ContainerAllocator> Type;

  orig_()
    : ID(0)
    , DATA()  {
      DATA.assign(0);
  }
  orig_(const ContainerAllocator& _alloc)
    : ID(0)
    , DATA()  {
  (void)_alloc;
      DATA.assign(0);
  }



   typedef int32_t _ID_type;
  _ID_type ID;

   typedef boost::array<int32_t, 8>  _DATA_type;
  _DATA_type DATA;




  typedef boost::shared_ptr< ::can_test_02::orig_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::can_test_02::orig_<ContainerAllocator> const> ConstPtr;

}; // struct orig_

typedef ::can_test_02::orig_<std::allocator<void> > orig;

typedef boost::shared_ptr< ::can_test_02::orig > origPtr;
typedef boost::shared_ptr< ::can_test_02::orig const> origConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::can_test_02::orig_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::can_test_02::orig_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace can_test_02

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'can_test_02': ['/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::can_test_02::orig_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::can_test_02::orig_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::can_test_02::orig_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::can_test_02::orig_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::can_test_02::orig_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::can_test_02::orig_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::can_test_02::orig_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6cb3802d33cdbc695753345038d6c344";
  }

  static const char* value(const ::can_test_02::orig_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6cb3802d33cdbc69ULL;
  static const uint64_t static_value2 = 0x5753345038d6c344ULL;
};

template<class ContainerAllocator>
struct DataType< ::can_test_02::orig_<ContainerAllocator> >
{
  static const char* value()
  {
    return "can_test_02/orig";
  }

  static const char* value(const ::can_test_02::orig_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::can_test_02::orig_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 ID\n\
int32[8] DATA\n\
";
  }

  static const char* value(const ::can_test_02::orig_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::can_test_02::orig_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ID);
      stream.next(m.DATA);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct orig_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::can_test_02::orig_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::can_test_02::orig_<ContainerAllocator>& v)
  {
    s << indent << "ID: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ID);
    s << indent << "DATA[]" << std::endl;
    for (size_t i = 0; i < v.DATA.size(); ++i)
    {
      s << indent << "  DATA[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.DATA[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAN_TEST_02_MESSAGE_ORIG_H
