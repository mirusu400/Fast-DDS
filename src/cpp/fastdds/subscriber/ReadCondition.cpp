// Copyright 2022 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file ReadCondition.cpp
 */

#include <fastdds/subscriber/ReadConditionImpl.hpp>

using namespace eprosima::fastdds::dds;

ReadCondition::ReadCondition()
{
}

ReadCondition::~ReadCondition()
{
}

bool ReadCondition::get_trigger_value() const noexcept
{
    assert((bool)impl_);
    return impl_->get_trigger_value();
}

DataReader* ReadCondition::get_datareader() const noexcept
{
    assert((bool)impl_);
    DataReader* dr = impl_->get_datareader();
    FILE* fp = fopen("/tmp/fastdds-debug", "a+");
    fprintf(fp, "ReadConditionImpl::get_datareader\t%p\n", dr);
    fclose(fp);
    return dr;
}

SampleStateMask ReadCondition::get_sample_state_mask() const noexcept
{
    assert((bool)impl_);
    SampleStateMask ssm = impl_->get_sample_state_mask();
    FILE* fp = fopen("/tmp/fastdds-debug", "a+");
    fprintf(fp, "ReadConditionImpl::get_sample_state_mask\t%d\n", ssm);
    fclose(fp);
    return ssm;
}

ViewStateMask ReadCondition::get_view_state_mask() const noexcept
{
    assert((bool)impl_);
    ViewStateMask vsm = impl_->get_view_state_mask();
    FILE* fp = fopen("/tmp/fastdds-debug", "a+");
    fprintf(fp, "ReadConditionImpl::get_view_state_mask\t%d\n", vsm);
    fclose(fp);
    return vsm;
}

InstanceStateMask ReadCondition::get_instance_state_mask() const noexcept
{
    assert((bool)impl_);
    InstanceStateMask ism = impl_->get_instance_state_mask();
    FILE* fp = fopen("/tmp/fastdds-debug", "a+");
    fprintf(fp, "ReadConditionImpl::get_instance_state_mask\t%d\n", ism);
    fclose(fp);
    return ism;
}
