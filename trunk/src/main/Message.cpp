/*
  Copyright 2007 Albert Strasheim <fullung@gmail.com>

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#include <boost/python/class.hpp>

#include <cms/Message.h>

namespace py = boost::python;

using cms::Message;

void export_Message()
{
    py::class_<Message, boost::noncopyable>("Message", py::no_init)
        .def("acknowledge", &Message::acknowledge)
        .def("clearBody", &Message::clearBody)
        .def("clearProperties", &Message::clearProperties)
        .add_property("propertyNames", &Message::getPropertyNames)
        .def("propertyExists", &Message::propertyExists)
        .def("getBooleanProperty", &Message::getBooleanProperty)
        .def("getByteProperty", &Message::getByteProperty)
        .def("getDoubleProperty", &Message::getDoubleProperty)
        .def("getFloatProperty", &Message::getFloatProperty)
        .def("getIntProperty", &Message::getIntProperty)
        .def("getLongProperty", &Message::getLongProperty)
        .def("getShortProperty", &Message::getShortProperty)
        .def("getStringProperty", &Message::getStringProperty)
        .def("setBooleanProperty", &Message::setBooleanProperty)
        .def("setByteProperty", &Message::setByteProperty)
        .def("setDoubleProperty", &Message::setDoubleProperty)
        .def("setFloatProperty", &Message::setFloatProperty)
        .def("setIntProperty", &Message::setIntProperty)
        .def("setLongProperty", &Message::setLongProperty)
        .def("setShortProperty", &Message::setShortProperty)
        .def("setStringProperty", &Message::setStringProperty)
        .add_property("correlationID", &Message::getCMSCorrelationID, &Message::setCMSCorrelationID)
        .add_property("deliveryMode", &Message::getCMSDeliveryMode, &Message::setCMSDeliveryMode)
        .add_property("destination",
                      make_function(&Message::getCMSDestination, py::return_internal_reference<>()),
                      make_function(&Message::setCMSDestination, py::with_custodian_and_ward<1, 2>()))
        .add_property("expiration", &Message::getCMSExpiration, &Message::setCMSExpiration)
        .add_property("messageID", &Message::getCMSMessageID, &Message::setCMSMessageID)
        .add_property("priority", &Message::getCMSPriority, &Message::setCMSPriority)
        .add_property("redelivered", &Message::getCMSRedelivered, &Message::setCMSRedelivered)
        .add_property("replyTo",
                      make_function(&Message::getCMSReplyTo, py::return_internal_reference<>()),
                      make_function(&Message::setCMSReplyTo, py::with_custodian_and_ward<1, 2>()))
        .add_property("timestamp", &Message::getCMSTimestamp, &Message::setCMSTimestamp)
        .add_property("type", &Message::getCMSType, &Message::setCMSType)
        ;
}