require 'faker'

AddressType.delete_all
%w[Home Work Other].each do |n|
  AddressType.create!(name: n)
end

def street
  s = Faker::Address.street_address
  return s if rand(2)
  s += "\n" + Faker::Address.secondary_address
end

def random_type
  AddressType.offset(rand(AddressType.count)).first.id
end

count = Rails.env.test? ? 20 : 1000
Entry.delete_all
count.times do
	#build first name, last name, and title
  entry = Entry.new(
    first_name: Faker::Name.first_name, last_name: Faker::Name.last_name,
    title: Faker::Name.title, avatar: "http://res.cloudinary.com/ulysseous/image/upload/v1367524814/default_k5sngh.png"
    )
  #build 4 addresses for each entry
  rand(4).times do |i|
    entry.addresses.build(
      address_type_id: random_type,
      street: street,
      city: Faker::Address.city,
      state: Faker::Address.state_abbr,
      zip: Faker::Address.zip_code.to_i
    )
  end
  #build 4 email addresses
  rand(4).times do |i|
    entry.emails.build(
      address_type_id: random_type,
      email: Faker::Internet.email,
      )
  end
  #build 4 web addresses
  rand(4).times do |i|
    entry.webs.build(
      address_type_id: random_type,
      web: Faker::Internet.domain_name,
      )
  end
  entry.save!
end

