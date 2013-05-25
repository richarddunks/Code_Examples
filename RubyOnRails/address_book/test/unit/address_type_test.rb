require 'test_helper'

class AddressTypeTest < ActiveSupport::TestCase
  test "Stringification of object is same as name" do
   a = AddressType.new(name: "foo")
   assert "#{a.name}"=="#{a}"
  end
  test "first entry in db is 'Home'" do
  	AddressType.first == 'Home'
  end
end
