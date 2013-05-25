class Email < ActiveRecord::Base
  belongs_to :entry
  belongs_to :address_type

  attr_accessible :address_type_id, :email, :entry_id

  #validate email address by REGEX
  validates_email_format_of :email

end
