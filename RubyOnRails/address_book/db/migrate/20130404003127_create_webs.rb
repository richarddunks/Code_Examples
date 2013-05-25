class CreateWebs < ActiveRecord::Migration
  def change
    create_table :webs do |t|
      t.integer :address_type_id
      t.string :web

      t.timestamps
    end
  end
end
