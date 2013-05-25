require 'test_helper'
require 'nested_test_helper'

class EntriesControllerTest < ActionController::TestCase
	test_nested(Address,
    address_type_id: AddressType.first.id,
    street: "13 Elm St", city: 'New York', state: 'NY', zip: 10001
    )
  test_nested(Email,
    email: "example@test.com", address_type_id: AddressType.first.id
    )
  test_nested(Web,
    web: "example.com", address_type_id: AddressType.last.id
    )

end
