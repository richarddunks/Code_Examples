class Web < ActiveRecord::Base
  belongs_to :entry
  belongs_to :address_type
  attr_accessible :address_type_id, :web, :entry_id
	
end
