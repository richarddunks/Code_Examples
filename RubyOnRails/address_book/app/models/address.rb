class Address < ActiveRecord::Base
  belongs_to :entry
  belongs_to :address_type
  attr_accessible :address_type_id, :city, :state, :street, :zip

  #validation for input
  validates :city, :state, :street, :zip, presence: true
  validates :zip, :numericality => {:greater_than_or_equal_to => 1, :message => "can't be blank"}
  validates :zip, :numericality => { :only_integer => true }
  validates :zip, :length => {:maximum => 5, 
    :too_long => "%{count} digits allowed for zip code" }
  
  def state=(val)
    write_attribute(:state, val.upcase)
  end
  
  def zip #override get-ter function
    "%05d" % read_attribute(:zip).to_i
  end

end
