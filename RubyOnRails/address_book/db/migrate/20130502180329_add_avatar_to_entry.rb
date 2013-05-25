class AddAvatarToEntry < ActiveRecord::Migration
  def change
    add_column :entries, :avatar, :string
  end
end
