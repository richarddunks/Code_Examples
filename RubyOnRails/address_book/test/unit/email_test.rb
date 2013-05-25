require 'test_helper'

class EmailTest < ActiveSupport::TestCase
  test "should not allow invalid address" do
    refute Email.new(email: "email").valid?
  end
end