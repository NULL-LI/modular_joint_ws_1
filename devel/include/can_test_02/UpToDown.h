// Generated by gencpp from file can_test_02/UpToDown.msg
// DO NOT EDIT!


#ifndef CAN_TEST_02_MESSAGE_UPTODOWN_H
#define CAN_TEST_02_MESSAGE_UPTODOWN_H


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
struct UpToDown_
{
  typedef UpToDown_<ContainerAllocator> Type;

  UpToDown_()
    : ID()
    , POSITION()
    , SPEED()
    , CURRENT()
    , MODE(0)  {
    }
  UpToDown_(const ContainerAllocator& _alloc)
    : ID(_alloc)
    , POSITION(_alloc)
    , SPEED(_alloc)
    , CURRENT(_alloc)
    , MODE(0)  {
  (void)_alloc;
    }



   typedef std::vector<int64_t, typename ContainerAllocator::template rebind<int64_t>::other >  _ID_type;
  _ID_type ID;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _POSITION_type;
  _POSITION_type POSITION;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _SPEED_type;
  _SPEED_type SPEED;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _CURRENT_type;
  _CURRENT_type CURRENT;

   typedef int64_t _MODE_type;
  _MODE_type MODE;




  typedef boost::shared_ptr< ::can_test_02::UpToDown_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::can_test_02::UpToDown_<ContainerAllocator> const> ConstPtr;

}; // struct UpToDown_

typedef ::can_test_02::UpToDown_<std::allocator<void> > UpToDown;

typedef boost::shared_ptr< ::can_test_02::UpToDown > UpToDownPtr;
typedef boost::shared_ptr< ::can_test_02::UpToDown const> UpToDownConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::can_test_02::UpToDown_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::can_test_02::UpToDown_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace can_test_02

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'can_test_02': ['/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::can_test_02::UpToDown_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::can_test_02::UpToDown_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::can_test_02::UpToDown_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::can_test_02::UpToDown_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::can_test_02::UpToDown_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::can_test_02::UpToDown_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::can_test_02::UpToDown_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c3ffbaef1f1d56ae7729ab1cfdc9dfb7";
  }

  static const char* value(const ::can_test_02::UpToDown_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc3ffbaef1f1d56aeULL;
  static const uint64_t static_value2 = 0x7729ab1cfdc9dfb7ULL;
};

template<class ContainerAllocator>
struct DataType< ::can_test_02::UpToDown_<ContainerAllocator> >
{
  static const char* value()
  {
    return "can_test_02/UpToDown";
  }

  static const char* value(const ::can_test_02::UpToDown_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::can_test_02::UpToDown_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64[] ID\n\
float64[] POSITION\n\
float64[] SPEED\n\
float64[] CURRENT\n\
int64 MODE\n\
\n\
\n\
";
  }

  static const char* value(const ::can_test_02::UpToDown_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::can_test_02::UpToDown_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ID);
      stream.next(m.POSITION);
      stream.next(m.SPEED);
      stream.next(m.CURRENT);
      stream.next(m.MODE);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct UpToDown_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::can_test_02::UpToDown_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::can_test_02::UpToDown_<ContainerAllocator>& v)
  {
    s << indent << "ID[]" << std::endl;
    for (size_t i = 0; i < v.ID.size(); ++i)
    {
      s << indent << "  ID[" << i << "]: ";
      Printer<int64_t>::stream(s, indent + "  ", v.ID[i]);
    }
    s << indent << "POSITION[]" << std::endl;
    for (size_t i = 0; i < v.POSITION.size(); ++i)
    {
      s << indent << "  POSITION[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.POSITION[i]);
    }
    s << indent << "SPEED[]" << std::endl;
    for (size_t i = 0; i < v.SPEED.size(); ++i)
    {
      s << indent << "  SPEED[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.SPEED[i]);
    }
    s << indent << "CURRENT[]" << std::endl;
    for (size_t i = 0; i < v.CURRENT.size(); ++i)
    {
      s << indent << "  CURRENT[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.CURRENT[i]);
    }
    s << indent << "MODE: ";
    Printer<int64_t>::stream(s, indent + "  ", v.MODE);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAN_TEST_02_MESSAGE_UPTODOWN_H
