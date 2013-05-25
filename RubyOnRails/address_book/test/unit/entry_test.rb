require 'test_helper'

class EntryTest < ActiveSupport::TestCase
  test "attributes must not be empty" do
    entry = entries( :empty )
    assert entry.invalid?
  end

  test "no first name" do
    entry = entries( :no_first_name )
    assert entry.invalid?
  end
  
  test "no last name" do
    entry = entries( :no_last_name)
    assert entry.invalid?
  end

  test "valid entry" do
    entry = entries( :valid )
    assert entry.valid?
  end  
  test "full name method concatenates name" do
    entry = entries(:valid)
    name = entries(:valid).full_name
    assert_match /\b#{entry.first_name}\b/, name, "Includes first name"
    assert_match /\b#{entry.last_name}\b/,  name, "Includes last name"
  end

end
