class CreateAddresses < ActiveRecord::Migration
  def change
    create_table :addresses do |t|
      t.text :street
      t.string :city
      t.string :state
      t.integer :zip
      t.integer :entry_id
      t.integer :address_type_id

      t.timestamps
    end
  end
end
