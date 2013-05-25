class AddressType < ActiveRecord::Base
  has_many :addresses
  has_many :emails
  has_many :webs
  accepts_nested_attributes_for :addresses, :emails, :webs
  attr_accessible :name

  def to_s
    name
  end

end
