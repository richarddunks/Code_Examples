require 'test_helper'

class AddressTest < ActiveSupport::TestCase
  test "address must not be empty" do
    address = addresses( :empty )
    assert address.invalid?
  end
  
  test "address must have number and street" do
    address = addresses( :no_street )
    assert address.invalid?
  end
  
  test "address must have city" do
    address = addresses( :no_city )
    assert address.invalid?
  end
  
  test "address must have a state" do
    address = addresses( :no_state )
    assert address.invalid?
  end
  
  test "address must have a zipcode" do
    address = addresses( :no_zip )
    assert address.invalid?
  end
  
  test "zipcode must be a number" do
  	address = addresses( :bad_zip )
  	assert address.invalid?
  end
  
  test "zipcode must be 5 digits or less" do
  	address = addresses( :long_zip )
  	assert address.invalid?
  end
  
end
