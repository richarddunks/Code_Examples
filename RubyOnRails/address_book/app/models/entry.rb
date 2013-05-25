class Entry < ActiveRecord::Base
  attr_accessible :first_name, :last_name, :title, :addresses_attributes, :webs_attributes, :emails_attributes, :avatar, :avatar_cache
  has_many :addresses, dependent: :destroy
  has_many :emails, dependent: :destroy
  has_many :webs, dependent: :destroy
  
  accepts_nested_attributes_for :addresses, :emails, :webs, allow_destroy: true, reject_if: :all_blank

  #validate entry isn't blank
  validates_presence_of :first_name, :last_name

	mount_uploader :avatar, PictureUploader
  
  def full_name
    "#{first_name} #{last_name}"
  end

end
